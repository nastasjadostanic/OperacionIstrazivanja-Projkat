#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct node {
    int val;
    struct node * next;
} node_t;

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

void printTables(string Table1[],string Table2[],string Table3[],string Table4[],string Table5[],string Table6[],string Table7[],string Table8[]){
    cout<< "         00:00  01:00  02:00  03:00  04:00  05:00  06:00  07:00  08:00  09:00  10:00 11:00 12:00 13:00 14:00 15:00 16:00 17:00 18:00 19:00 20:00 21:00 22:00 23:00";
    cout << "\n";
    cout << "TABLE 1 :";
    for (int i=0;i<24;i++)
    cout <<Table1[i]<< " ";

    cout << "\n";
    cout << "TABLE 2 :";
    for (int i=0;i<24;i++)
    cout <<Table2[i]<< " ";

    cout << "\n";
    cout << "TABLE 3 :";
    for (int i=0;i<24;i++)
    cout <<Table3[i]<< " ";

    cout << "\n";
    cout << "TABLE 4 :";
    for (int i=0;i<24;i++)
    cout <<Table4[i]<< " ";

    cout << "\n";
    cout << "TABLE 5 :";
    for (int i=0;i<24;i++)
    cout <<Table5[i]<< " ";

    cout << "\n";
    cout << "TABLE 6 :";
    for (int i=0;i<24;i++)
    cout <<Table6[i]<< " ";

    cout << "\n";
    cout << "TABLE 7 :";
    for (int i=0;i<24;i++)
    cout <<Table7[i]<< " ";

    cout << "\n";
    cout << "TABLE 8 :";
    for (int i=0;i<24;i++)
    cout <<Table8[i]<< " ";

    cout << "\n";


}

int scheduleTable(string Table1[],string Table2[],string Table3[],string Table4[],string Table5[],string Table6[],string Table7[],string Table8[], int time, int numberOfPeople, string name, int duration){
    int scheduled = 0;
    if(numberOfPeople<3){ //STO ZA DVOJE

            if (Table1[time] == "empty") {      //PRVI STO

                for (int i=time;i<time+duration;i++){
                    if(Table1[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table1[i]=name;
                    }
                return 1;
                }
            }


            scheduled=0;
            if (Table2[time] == "empty") {      //DRUGI STO

                for (int i=time;i<time+duration;i++){
                    if(Table2[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table2[i]=name;
                    }
                return 1;
                }
            }

            scheduled=0;
            if (Table3[time] == "empty") {      //TRECI STO

                for (int i=time;i<time+duration;i++){
                    if(Table3[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table3[i]=name;
                    }
                return 1;
                }
            }

            scheduled=0;
            if (Table4[time] == "empty") {      //CETVRTI STO

                for (int i=time;i<time+duration;i++){
                    if(Table4[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table4[i]=name;
                    }
                return 1;
                }
            }
                return 0; //ako je sve dosad neuspesno

    }



    if(numberOfPeople>=3){                  // STO ZA CETVORO

        if (Table5[time] == "empty") {      //PETI STO

                for (int i=time;i<time+duration;i++){
                    if(Table5[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table5[i]=name;
                    }
                return 1;
                }
            }


            scheduled=0;
            if (Table6[time] == "empty") {      //SESTI STO

                for (int i=time;i<time+duration;i++){
                    if(Table6[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table6[i]=name;
                    }
                return 1;
                }
            }

            scheduled=0;
            if (Table7[time] == "empty") {      //SEDMI STO

                for (int i=time;i<time+duration;i++){
                    if(Table7[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table7[i]=name;
                    }
                return 1;
                }
            }

            scheduled=0;
            if (Table8[time] == "empty") {      //OSMI STO

                for (int i=time;i<time+duration;i++){
                    if(Table8[i]!= "empty") {scheduled = 1;break;}
                }

                if (scheduled == 0){
                    for (int i=time;i<time+duration;i++){
                        Table8[i]=name;
                    }
                return 1;
                }
            }
    }
    return 0;//ako je sve dosad neuspesno
    }

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tryArray(int arr[], int size,node_t *output){
    int i;
    int perms=0;

    for(i=0; i<size; i++) //arr[i]-ovi sadrze trenutnu permutaciju
    {                             //1,10,100...
         perms=perms + (arr[i] * pow(10,i));

    }
    push(output, perms);
   // cout<< output[start]<<"\n";


}

void permutation(int *arr, int start, int end, node_t *output){

    if(start==end)
    {
        tryArray(arr, end+1,output);


        return;
    }

    int i;
    for(i=start;i<=end;i++)
    {

        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits

        permutation(arr, start+1, end,output);
        swap((arr+i), (arr+start));
    }
}

void createArrayOfReservations(string Table1[],string Table2[],string Table3[],string Table4[],int time, string name, int duration,int reservationTime[], int reservationDuration[], string reservationName[]){
    int tempTime,tempDuration;
    int cnt =0;
    string tempName;

    for (int i=0; i <24; i++){                              //TABLE1
        if(Table1[i]!= "closed" && Table1[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table1[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table1[j]!= Table1[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }
            reservationName[cnt]= tempName;
            reservationDuration[cnt]= tempDuration-1;
            reservationTime[cnt]= tempTime;
            cnt++;
            i=j-1;

        }
    }


    for (int i=0; i <24; i++){                          //TABLE 2
        if(Table2[i]!= "closed" && Table2[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table2[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table2[j]!= Table2[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }
            reservationName[cnt]= tempName;
            reservationDuration[cnt]= tempDuration-1;
            reservationTime[cnt]= tempTime;
            cnt++;
            i=j-1;

        }
    }

    for (int i=0; i <24; i++){                          //TABLE 3
        if(Table3[i]!= "closed" && Table3[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table3[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table3[j]!= Table3[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }
            reservationName[cnt]= tempName;
            reservationDuration[cnt]= tempDuration-1;
            reservationTime[cnt]= tempTime;
            cnt++;
            i=j-1;

        }
    }

    for (int i=0; i <24; i++){                          //TABLE 3
        if(Table4[i]!= "closed" && Table4[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table4[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table4[j]!= Table4[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }
            reservationName[cnt]= tempName;
            reservationDuration[cnt]= tempDuration-1;
            reservationTime[cnt]= tempTime;
            cnt++;
            i=j-1;

        }
    }

            reservationName[cnt]= name;             //poslednji koji dodajemo trenutno
            reservationDuration[cnt]= duration;
            reservationTime[cnt]= time;


}
//ako je za dvoje prosledi 1234, ako je za cetvoro prosledi 5678
//funkcija vraca 3 paralelna niza
int factorial(int n){
    int f=1;
    for (int i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}

int numberOfReservations(string Table1[],string Table2[],string Table3[],string Table4[]){
    int tempTime,tempDuration;
    int cnt =0;
    string tempName;

    for (int i=0; i <24; i++){                              //TABLE1
        if(Table1[i]!= "closed" && Table1[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table1[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table1[j]!= Table1[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }

            cnt++;
            i=j-1;

        }
    }


    for (int i=0; i <24; i++){                          //TABLE 2
        if(Table2[i]!= "closed" && Table2[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table2[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table2[j]!= Table2[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }

            cnt++;
            i=j-1;
        }
    }

    for (int i=0; i <24; i++){                          //TABLE 3
        if(Table3[i]!= "closed" && Table3[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table3[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table3[j]!= Table3[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }

            cnt++;
            i=j-1;

        }
    }

    for (int i=0; i <24; i++){                          //TABLE 3
        if(Table4[i]!= "closed" && Table4[i]!= "empty"){
            tempTime= i;
            tempDuration= 1;
            tempName= Table4[i];
            int j;
            for(j=i;j<i+5;j++){
                if (j>23) {break;}                  //ako izadje van 24h
                if(Table4[j]!= Table4[i]){break;}   //Ako su razliciti zaustavlja se
                tempDuration++;
            }

            cnt++;
            i=j-1;

        }
    }
return cnt;


}

int scramble(string Table1[],string Table2[],string Table3[],string Table4[],string Table5[],string Table6[],string Table7[],string Table8[], int time, int numberOfPeople, string name, int duration){

    cout<< "SCRAMBLING...\n";

    if(numberOfPeople<=2){
    string TempTable1[24];
    string TempTable2[24];
    string TempTable3[24];
    string TempTable4[24];

    string TempTable5[24];
    string TempTable6[24];
    string TempTable7[24];
    string TempTable8[24];

    for(int i=0;i<24;i++){          // tables copies
        TempTable1[i]= Table1[i];
        TempTable2[i]= Table2[i];
        TempTable3[i]= Table3[i];
        TempTable4[i]= Table4[i];

        TempTable5[i]= Table5[i];
        TempTable6[i]= Table6[i];
        TempTable7[i]= Table7[i];
        TempTable8[i]= Table8[i];
   }
    //1 treba procitati iz originalnih tabela podatke i smestiti u 3 paralelna niza po *i* i prebrojati ih

    int numOfReservations = numberOfReservations(TempTable1,TempTable2,TempTable3,TempTable4) +1;  //koliko ih ima

    int times[numOfReservations];
    int durations[numOfReservations];
    string names[56];

    createArrayOfReservations(TempTable1,TempTable2,TempTable3,TempTable4,time,name,duration,times,durations,names);


    //2 prave se sve permutacije pomocu dole navedenog algoritma


    int i;

    int arr[numOfReservations];
    for(i=0;i<=numOfReservations;i++){
        arr[i]=i+1;
      //cout<< arr[i]<<"\n";
    }

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->next=NULL;
    permutation(arr, 0, numOfReservations, head);
    pop(&head); // brisanje smeca sa prvog mesta
    //print_list(head);


    //3 pomocu scheduleTable se pokusava zakazati sve iz nizova(sa novim clanom) : ukoliko radi, sacuvati tu kopiju tabela u original; ukoliko ne radi, obrisati kopije i napraviti nove iz sledece permutacije
    node_t * current = head;
    while (current != NULL) { // prolaz kroz sve permutacije iz liste

    string Table1Empty[24] = {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table2Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table3Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table4Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    //tables for 2

    string Table5Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table6Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table7Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table8Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};

    int TRUTH=1;
        for(int i=0; i<numOfReservations;i++){ //prolaz kroz sve cifre jedne varijacije

            if(scheduleTable(Table1Empty,Table2Empty,Table3Empty,Table4Empty,Table5Empty,Table6Empty,Table7Empty,Table8Empty,times[(current->val % 10)-1],2,names[(current->val % 10)-1],durations[(current->val % 10)-1] ) ==0){
                TRUTH=0;
                break;
            }
            current->val = current->val/10;

        }

       if (TRUTH == 1){
            for(int i=0;i<24;i++){          //pise resenje u main tabele i izlazi is funkcije
                Table1[i] = Table1Empty[i];
                Table2[i] = Table2Empty[i];
                Table3[i] = Table3Empty[i];
                Table4[i] = Table4Empty[i];

            }
            return 1;
       }





        current = current->next;
        }


    return 0;



    //4 algoritam se zavrsava kada prodje kroz sve(neuspesno) ili ukoliko pronadje kombinaciju gde moze da se zakaze

}
else{
    string TempTable1[24];
    string TempTable2[24];
    string TempTable3[24];
    string TempTable4[24];

    string TempTable5[24];
    string TempTable6[24];
    string TempTable7[24];
    string TempTable8[24];

    for(int i=0;i<24;i++){          // tables copies
        TempTable1[i]= Table1[i];
        TempTable2[i]= Table2[i];
        TempTable3[i]= Table3[i];
        TempTable4[i]= Table4[i];

        TempTable5[i]= Table5[i];
        TempTable6[i]= Table6[i];
        TempTable7[i]= Table7[i];
        TempTable8[i]= Table8[i];
   }
    //1 treba procitati iz originalnih tabela podatke i smestiti u 3 paralelna niza po *i* i prebrojati ih

    int numOfReservations = numberOfReservations(TempTable5,TempTable6,TempTable7,TempTable8) +1;  //koliko ih ima

    int times[numOfReservations];
    int durations[numOfReservations];
    string names[56];

    createArrayOfReservations(TempTable5,TempTable6,TempTable7,TempTable8,time,name,duration,times,durations,names);


    //2 prave se sve permutacije pomocu dole navedenog algoritma


    int i;

    int arr[numOfReservations];
    for(i=0;i<=numOfReservations;i++){
        arr[i]=i+1;
      //cout<< arr[i]<<"\n";
    }

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->next=NULL;
    permutation(arr, 0, numOfReservations, head);
    pop(&head); // brisanje smeca sa prvog mesta
    //print_list(head);


    //3 pomocu scheduleTable se pokusava zakazati sve iz nizova(sa novim clanom) : ukoliko radi, sacuvati tu kopiju tabela u original; ukoliko ne radi, obrisati kopije i napraviti nove iz sledece permutacije
    node_t * current = head;
    while (current != NULL) { // prolaz kroz sve permutacije iz liste

    string Table1Empty[24] = {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table2Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table3Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table4Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    //tables for 2

    string Table5Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table6Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table7Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table8Empty[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};

    int TRUTH=1;
        for(int i=0; i<numOfReservations;i++){ //prolaz kroz sve cifre jedne varijacije

            if(scheduleTable(Table1Empty,Table2Empty,Table3Empty,Table4Empty,Table5Empty,Table6Empty,Table7Empty,Table8Empty,times[(current->val % 10)-1],4,names[(current->val % 10)-1],durations[(current->val % 10)-1] ) ==0){
                TRUTH=0;
                break;
            }
            current->val = current->val/10;

        }

       if (TRUTH == 1){
            for(int i=0;i<24;i++){          //pise resenje u main tabele i izlazi is funkcije
                Table5[i] = Table5Empty[i];
                Table6[i] = Table6Empty[i];
                Table7[i] = Table7Empty[i];
                Table8[i] = Table8Empty[i];

            }
            return 1;
       }





        current = current->next;
        }


    return 0;

}

}



int main()
{

    string Table1[24] = {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","DAVID","DAVID","empty","BBBBB","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table2[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","XXXXX","XXXXX","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table3[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","DDDDD","DDDDD","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table4[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","AAAAA","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    //tables for 2

    string Table5[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","DAVID","DAVID","empty","BBBBB","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table6[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","XXXXX","XXXXX","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table7[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","DDDDD","DDDDD","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    string Table8[24]=  {"closed","closed","closed","closed","closed","closed","closed","closed","closed","closed","empty","empty","AAAAA","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    //tables for 4

    //restaurant opens at 10:00
                                            //12              20
    int demandTwo[24] =    {0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,3,3,2,3,5,2,3,6,6};
    int demandFour[24] =   {0,0,0,0,0,0,0,0,0,0,1,0,1,5,5,2,2,2,1,3,4,3,2,1};



    //menu
    int choice=1;
    while(choice!=0){
        cout << "\n";
        //user selects a choice
        cout<< "WELCOME TO RESERVATION SYSTEM \n"<<endl;
        cout<< "1 - Reserve a table \n" <<endl;
        cout<< "2 - See table availability \n" <<endl;
        //cout<< "3 - Number of reservations \n" <<endl;
        //cout<< "4 - Scramble \n" <<endl;

        cout<< "0 - Exit \n" <<endl;

        //user input
        cin>> choice;

        //reserve a table
        if(choice == 1){
            //call a function for reservation
            int time,numberOfPeople,duration;
            string name;
            cout << "Time :";
            cin>> time;

            if(time<10 && time>=0){
                    cout<< "We are closed at " << time;
                    continue;}
            else{
                    if(time<0 || time>23){
                        cout<< "Invalid time";
                        continue;}}

            cout << "Duration :";
            cin>> duration;

            if(duration > 5 || time+duration >24 || duration < 1){cout<<"Invalid duration";continue;};

            cout << "Number of people :";
            cin>> numberOfPeople;
            if( numberOfPeople<1 || numberOfPeople >4){cout << "Invalid number"; continue;}

            cout << "Name :";
            cin>> name;


            if(scheduleTable(Table1,Table2,Table3,Table4,Table5,Table6,Table7,Table8,time,numberOfPeople,name,duration) == 1) {
                    cout << "RESERVATION SUCCESSFUL\n";
                    }


            else {
                    cout << "NO FREE TABLES\n" ;
                    if(scramble(Table1,Table2,Table3,Table4,Table5,Table6,Table7,Table8,time,numberOfPeople,name,duration) == 1)
                        cout<< "SCRAMBLE SUCCESSFUL\n";
                    else
                        cout<< "NO FREE TABLES AVAILABLE\n";
            };


        }
        if(choice ==2) {
            //call of a function for printing tables
            printTables(Table1,Table2,Table3,Table4,Table5,Table6,Table7,Table8);
        }

        if(choice ==3) {
            //call of a function for printing tables
            int resCnt = numberOfReservations(Table1,Table2,Table3,Table4);
            cout << "Number of reservations is: " <<resCnt;

        }

        if(choice ==4) {
                if(scramble(Table1,Table2,Table3,Table4,Table5,Table6,Table7,Table8,12,2,"SCRAM",2) == 1)
                    cout<< "I DID SCRAMBLE SUCCESSFULY\n";
                else cout<< "I DID NOT DO SCRAMBLE SUCCESSFULY\n";


        }

        }


    return 0;
}



