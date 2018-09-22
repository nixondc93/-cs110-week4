#include <iostream>
using namespace std;

void userPrompt(int arr[21]){
  int choice;
  cout << "Please choose a number from the list and remember it.";

  for(int i = 0; i < 21; i++){
    cout << " " << arr[i];
  }
  cout << "\n\nPress Enter to continue.\n";
  cin.get();
}

void buildPiles(int firstArr[7], int secondArr[7], int thirdArr[7], int mainArr[21]){
  int count = 0;
  for(int i = 0; i < 21; i += 3){
    firstArr[count] = mainArr[i];
    secondArr[count] = mainArr[i + 1];
    thirdArr[count] = mainArr[i + 2];
    count++;
  }
}

int pilePrompt(int firstArr[7], int secondArr[7], int thirdArr[7]){
  int choice;
  for(int i = 0; i < 7; i++){
    cout << firstArr[i] << " ";
  }
  cout << "  pile: 1" << endl;
  for(int j = 0; j < 7; j++){
    cout << secondArr[j] << " ";
  }
  cout << "  pile: 2" << endl;
  for(int k = 0; k < 7; k++){
    cout << thirdArr[k] << " ";
  }
  cout << "  pile: 3" << endl;
  cout << "Which Pile is your number in? Enter 1, 2, or 3." << endl;
  cin >> choice;

  return choice;
}

void shuffleMainArr(int firstArr[7], int secondArr[7], int thirdArr[7], int mainArr[21], int choice){
  if(choice == 1){
    int pileIdx = 0;
    for(int i = 0; i < 21; i++){
      if(i < 7){
        mainArr[i] = secondArr[pileIdx];
        pileIdx++;
      }else if(i < 14){
        mainArr[i] = firstArr[pileIdx];
        pileIdx++;
      }else{
        mainArr[i] = thirdArr[pileIdx];
        pileIdx++;
      }
      if(i == 6 || i == 13){
        pileIdx = 0;
      }
    }
  }else if(choice == 2){
    int pileIdx = 0;
    for(int i = 0; i < 21; i++){
      if(i < 7){
        mainArr[i] = firstArr[pileIdx];
        pileIdx++;
      }else if(i < 14){
        mainArr[i] = secondArr[pileIdx];
        pileIdx++;
      }else{
        mainArr[i] = thirdArr[pileIdx];
        pileIdx++;
      }
      if(i == 6 || i == 13){
        pileIdx = 0;
      }
    }
  }else{
    int pileIdx = 0;
    for(int i = 0; i < 21; i++){
      if(i < 7){
        mainArr[i] = firstArr[pileIdx];
        pileIdx++;
      }else if(i < 14){
        mainArr[i] = thirdArr[pileIdx];
        pileIdx++;
      }else{
        mainArr[i] = secondArr[pileIdx];
        pileIdx++;
      }
      if(i == 6 || i == 13){
        pileIdx = 0;
      }
    }
  }
}

int findUserCard(int mainArr[21]){
  return mainArr[10];
}

void numberGuessGame(){
  int mainArr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
  int firstArr[7], secondArr[7], thirdArr[7];
  int choice;

  userPrompt(mainArr);

  for(int i = 0; i < 3; i++){
    buildPiles(firstArr, secondArr, thirdArr, mainArr);
    choice = pilePrompt(firstArr, secondArr, thirdArr);
    shuffleMainArr(firstArr, secondArr, thirdArr, mainArr, choice);
  }

  cout << "\n\nIs this your number " << findUserCard(mainArr) << "?\n";
}

int main() {

  numberGuessGame();

  return 0;
}