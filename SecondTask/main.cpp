#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct graphElement {
    char nameOfElement;
    char nextTrueElement;
    char nextFalseElement;
};

void helloInfo();
int getGraphSize();
bool isRightInput(int choiceOfSize);
bool isRightChar(int maxAlphabetSign);
void fillMachine(struct graphElement machine[], size_t graphSize);
char chooseNextState();
void playTheGame(struct graphElement machine[], size_t graphSize);



int main() {

    int graphSize = 0;
    helloInfo();
    graphSize = getGraphSize();
    graphElement stateMachine[graphSize];
    fillMachine(stateMachine, graphSize);
    playTheGame(stateMachine,graphSize);
    return 0;
}

void helloInfo(){

    cout << " Welcome in 2nd project. Give me your choice of graph size ( up to 20 ):" << endl;

}

bool isRightInput(int choiceOfSize){

    return choiceOfSize <= 0 || choiceOfSize > 20;

}

bool isRightChar(char choice, int maxAlphabetSign){

    return ((choice >= 'A' && choice < (char) ('A' + maxAlphabetSign)) || (choice >= 'a' && choice < (char) ('a' + maxAlphabetSign)));

}

int getGraphSize(){

    int choiceOfGraphSize = 0;

    while ( isRightInput(choiceOfGraphSize)) {
        cin >> choiceOfGraphSize;
        while ( cin.fail()){
            cout << "Wrong format. Please type integer " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> choiceOfGraphSize;
        }
    }

    return choiceOfGraphSize;

}

char chooseNextState( int maxAlphabetSign ){

    char choice;
    do {
        cin >> choice;
    } while (!isRightChar(choice, maxAlphabetSign));


    if(choice >= 'a' && choice <= 'z'){
            choice = choice - 32;
            return choice;
        }
    else
            return choice;
}

void fillMachine(struct graphElement machine[], size_t length){

    for(int i = 0; i < length; i++)
        machine[i].nameOfElement = (char) ('A' + i);



    for(int i = 0; i < length; i++){

        cout << "Next state for true pass from " << machine[i].nameOfElement << " : " << endl;
        machine[i].nextTrueElement = chooseNextState(length);
        cout << "Next state for false pass from " << machine[i].nameOfElement << " : " << endl;
        machine[i].nextFalseElement = chooseNextState(length);

    }


}







void playTheGame(struct graphElement machine[], size_t graphSize){

    cout << "Please type your sequence (...1010001...) " << endl;
    char buffer[256] = {'\0'};
    char c;
    int index = 0;
    int counter = 0;
    struct graphElement element = machine[0];
    char signOfElement = machine[0].nameOfElement;

    cin>>c;

    while (1)
    {

        if ( c== '1' || c== '0')
        {
            buffer[index] = c;  /* Ignoring buffer overflow - bad! */
            index++;
        }
        else if ( c=='E')
            break;
        else
            cout << "Wrong type (1/0)" << endl;
        cin >> c;

    }

    cout << "\n\n Your sequence is" << endl;
    cout << signOfElement << endl;

    for(counter = 0; counter < index; counter++){


        if ( buffer[counter] == '1')
            signOfElement = element.nextTrueElement;
        else
            signOfElement = element.nextFalseElement;
        cout << signOfElement << endl;
        element = machine[(int)(signOfElement - 65)];

    }


}