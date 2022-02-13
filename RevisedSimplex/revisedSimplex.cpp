#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double finalResault = 0.0;
// m= number of constraints, n=number of varialble
static size_t m,n;

// a structure that represents a basic variable
struct variable {
    size_t label;
    double value;
};

// a structure that represents an eta matrix-for updating b
struct eta {
    size_t col;
    vector<double> values;
};

// print out the final values of decision variables and slack variables
void printFinalVariables(variable b[], size_t nonbasic[]) {
    double varValues[m + n];

    for (size_t row = 0; row < m; ++row) {
        varValues[b[row].label] = b[row].value;
    }

    for (size_t col = 0; col < n; ++col) {
        varValues[nonbasic[col]] = 0.0;
    }

    // decision variables
    printf("Decision variables: ");

    for (size_t i = 0; i < n; ++i) {
        printf("x%lu = %5.3f ", i + 1, varValues[i]);
    }

    // slack variables
    printf("\nSlack variables: ");

    for (size_t i = n; i < m + n; ++i) {
        printf("x%lu = %5.3f ", i + 1, varValues[i]);
    }

    printf("\n");
}

int main(int argc, const char * argv[]) {

    // Read in the number of constraints and the number of variables
    cout << "\n NUMBER OF CONSTRAINTS? ";
    cin >> m;
    cout << "\n NUMBER OF VARIABLES? ";
    cin >> n;

    // Coefficients in the objective function
    double objFuncCoeff[n + m];

    cout<<"\n INPUT COEFFICIENTS OF THE FUNCTION:\n";
    // Read in the coefficients in the objective function
    for (size_t col = 0; col < n; ++col) {
        cin >> objFuncCoeff[col];
    }
    // Matrix A represented as a 1-D array with rows stacked next to each other
    double A[m * (n + m)];
 // Column of labels and values of the basic variables in the basic feasible solution
    variable b[m];
    // Column of variable (only with labels, from 0 to m + n - 1) of the nonbasic variables
    size_t nonbasic[n];

    cout<<"\n INPUT COEFFICIENTS OF THE CONSTRAINTS:\n";
    for (size_t row = 0; row < m; ++row) {
        for (size_t col = 0; col <= n; ++col) {
            if (col == n) {
                double bRow;
                cin >> bRow;
                variable bVar = {n + row, bRow};
                b[row] = bVar;
            } else {
                cin >> A[row * (m + n) + col];
            }
        }
    }

    // Initialize columns for slack variables in matrix A
    for (size_t row = 0; row < m; ++row) {
        size_t base = (m + n) * row + n;
        for (size_t col = 0; col < m; ++col) {
            if (col != row) {
                A[base + col] = 0.0;
            } else {
                A[base + col] = 1.0;
            }
        }
    }
    // Initialize the nonbasic variables' labels to be 0 through (n - 1)
    for (size_t i = 0; i < n; ++i) {
        nonbasic[i] = i;
    }

    // Initial basic solution is feasible, now proceed with the Simplex Method
    // A counter to remember the current iteration number
    size_t counter = 1;

    // An array of eta matrices representing previous pivots
    vector<eta> pivots{};

    // Initial value of objective function
    double z = 0.0;

    // Revised Simplex Method
    while (true) {
        // compute y using eta matrices (yB = Cb)
        vector<double> y(m);

        // initialize y to be Cb
        for (size_t row = 0; row < m; ++row) {
            variable v = b[row];
            y[row] = objFuncCoeff[v.label];
        }

        // solving y in yB = Cb
        for (auto rIter = pivots.crbegin(); rIter != pivots.crend(); ++rIter) {
            eta pivot = *rIter;
            size_t colToChange = pivot.col;
            double yOriginal = y[colToChange];

            for (size_t row = 0; row < pivot.values.size(); ++row) {
                if (row != colToChange) {
                    yOriginal -= pivot.values[row] * y[row];
                }
            }

            double yNew = yOriginal / pivot.values[colToChange];
            y[colToChange] = yNew;
        }

        // choose an entering column using the condition Cn > ya, where "a" is a column of An a vector to keep track of the variables whose coefficients in the objective function in this iteration are positive

        vector<variable> cnbars;

        size_t enteringLabel = nonbasic[0];
        double largestCoeff = -1.0;

        for (size_t i = 0; i < n; ++i) {
            size_t varLabel = nonbasic[i];
            double cni = objFuncCoeff[varLabel];
            double yai = 0.0;

            for (size_t yIndex = 0; yIndex < m; ++yIndex) {
                yai += y[yIndex] * A[yIndex * (m + n) + varLabel];
            }

            double cnbar = cni - yai;

            if (cnbar > 0.00001) {
                variable v = {varLabel, cnbar};

                cnbars.push_back(v);

                if (cnbar > largestCoeff) {
                    largestCoeff = cnbar;
                    enteringLabel = varLabel;
                }
            }
        }



        size_t enteringVariable_index = 0;

        // compute the column d in Anbar for the entering variable using eta matrices (Bd = a)

        vector<double> d(m);

        size_t leavingLabel;
        size_t leavingRow;
        double smallest_t;

        while (true) {

            leavingLabel = -1;
            leavingRow = -1;
            smallest_t = -1;

            if (enteringVariable_index < cnbars.size()) {
                enteringLabel = cnbars[enteringVariable_index].label;

            } else {
                printFinalVariables(b, nonbasic);
                return 0;
            }

            // initialize d to be the entering column a
            for (size_t row = 0; row < m; ++row) {
                d[row] = A[row * (m + n) + enteringLabel];
            }

            // Go through eta matrices from pivot 1 to pivot k
            for (auto iter = pivots.cbegin(); iter != pivots.cend(); ++iter) {
                eta pivot = *iter;
                size_t rowToChange = pivot.col;
                double dOriginal = d[rowToChange];

                d[rowToChange] = dOriginal / pivot.values[rowToChange];

                for (size_t row = 0; row < d.size(); ++row) {
                    if (row != rowToChange) {
                        d[row] = d[row] - pivot.values[row] * d[rowToChange];
                    }
                }
            }

            // compute t for each b[i].value / d[i] where d[i] > 0 choose the corresponding i for the smallest ratio as the leaving variable

            // initialize smallest_t to be the first ratio where the coefficient of the entering variable in that row is negative
            for (size_t row = 0; row < d.size(); ++row) {
                if (d[row] > 0.0) {
                    leavingLabel = b[row].label;
                    leavingRow = row;
                    smallest_t = b[row].value / d[row];
                }
            }

            for (size_t row = 0; row < d.size(); ++row) {

                double t_row = b[row].value / d[row];

                if (t_row < smallest_t) {
                    leavingLabel = b[row].label;
                    leavingRow = row;
                    smallest_t = t_row;
                }
            }

            // check the diagonal element in the eta column to see if the current choice of entering variable has to be rejected
           if (d[leavingRow] > 0.00000001) {
                break;
            } else {
                enteringVariable_index++;
                continue;

        }

        // At this point we have a pair of entering and leaving variables so that the entering variable is positive and the diagonal entry in the eta column of the eta matrix is fairly far from zero

        // set the value of the entering varaible at t , modify b (change leaving variable to entering variable, change values of other basic vars)
        variable enteringVar = {enteringLabel, smallest_t};
        b[leavingRow] = enteringVar;

        for (size_t row = 0; row < sizeof(b) / sizeof(b[0]); ++row) {
            if (row != leavingRow) {
                b[row].value -= d[row] * smallest_t;
            }
        }

        // push a new eta matrix onto the vector
        eta pivot = {leavingRow, d};
        pivots.push_back(pivot);

        nonbasic[enteringLabel] = leavingLabel;

        // increase the value of the objective function
        double increasedValue =largestCoeff * smallest_t;


        double originalZ = z;
        z += increasedValue;

        counter++;

    finalResault==z;

    }

cout<<finalResault; //why you do not want to work?
printf("Value of the function is %5.3f\n\n\n", finalResault); // or you?

    return 0;
}}
