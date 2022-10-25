#include<fstream>
#include<iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; //stores filename


void readFileData(ListNode **headNode) //reads text from a file. You should add functionality to store the fetched data into a singly linked list. 
{
  Dictionary *dict;
  string word, meaning;
  fstream fin;
  cout << "\e[46mEnter the filename\x1b[0m "; 
  cin.ignore();
  cin >> filename;
  fin.open(filename);
  cout << "\e[0;32mFile reading succesful.\x1b[0m\n";
  while (fin >> word)  //reads from the file word by word
  {
      fin.ignore();
      getline(fin, meaning);
      dict = new Dictionary(word, meaning); //Dynamically creating an instance of class Dictionary

      ListNode* newnode = new ListNode;
      newnode->data = *dict;
      if (*headNode != NULL) //True if the list is not empty
      {
          ListNode* loc = *headNode;
          for (loc->next != NULL; loc = loc->next;) //Traversing through the list
          loc->next = newnode;
      }
      else //If the list is empty
      {
          *headNode = newnode;
      }

      delete dict;
  }
  fin.close();
}

void writeToFile(ListNode *headNode) //write the linked list to a text file
{
  string word, meaning;
  
  fstream dictFile; //create fstream object for the file
  cout << "\e[46mEnter the filename\x1b[0m "; 
    cin.ignore();
  cin >> filename;
  dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

  ListNode* loc = headNode;
  while (loc != NULL) //Loop runs unless loc becomes null 
  {
      dictFile << loc->data.word << " " << loc->data.meaning << "\n"; //writing data to the file
      loc = loc->next;
  }
  dictFile.close(); //closing the file
  cout << "\e[0;32mDictionary entries added.\x1b[0m\n";
}


void mainMenu() //menu function
{
  string word, meaning; //stores the word and meaning
  char choice = 0;  //stores user choice for the actions
  SinglyLL<Dictionary> list;

  cout << "\e[1;35mInput 's' to terminate the program anytime.\e[0;37m" << endl;
  while (choice != 's') //while loop until 's' is entered
  {
    cout << "\n\x1b[36mPlease select an action: " << endl << endl;
    cout << "\t1. Read file data" << endl;
    cout << "\t2. Write to file" << endl;
    cout << "\t3. Print List" << endl;
    cout << "\t4. Reverse print the list" << endl;
    cout << "\t5. Reverse the list" << endl;
    cout << "\t6. Rearrange list by odd/even length" << endl;
    cout << "\t7. Filter list by letter" << endl;
    
    

    cout << "\x1b[0m"; cin >> choice; cout << endl;
    switch(choice)  //switch statement to check user input and calling respective functions
    {
      case('1'):
      {
        readFileData(&list.start);
      }; break;
      case('2'):
      {
        writeToFile(list.start);
      }; break;
      case('3'):
      {
          list.print(list.start);
      }; break;
      case('4'):
      {
          list.printReverse(list.start);
      }break;
      case('5'):
      {
          list.start=list.reverseList(list.start);
      }break;
      case('6'):
      {
          list.start = list.rearrangeByEvenOddLength(list.start);
          cout << "The list is rearranged";
      }break;
      case('7'):
      {
          cout << "Enter the letter you want to filter the list with:";
          string L;
          cin.ignore();
          cin >> L;
          list.filterByLetter(list.start, L);
          cout << "The list if filtered!";
      }break;
      case('s'):
      {
        cout << "\e[1;33mProgram terminated." << endl;
      }; break;
      default:
        cout << "\x1b[31mInvalid action selected!\x1b[37m" << endl;
    }
  }
}