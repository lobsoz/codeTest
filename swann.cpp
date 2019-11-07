
#include <iostream>
#include <algorithm>  
#include <fstream>
#include <array> 

using namespace std;

class Anagrams {
   protected:
      string inputPhrase;
      string* anagramList = new string[0];
      
   public:
      Anagrams( string input){
         std::for_each(input.begin(), input.end(), [](char & c){
        	c = ::tolower(c);
        });
        inputPhrase = input;
      }
      void findAnagrams() {
         sort(inputPhrase.begin(), inputPhrase.end());
         searchFileForAnagram();
         return;
      }
      
      void searchFileForAnagram()
      {
         
         ifstream inFile;
         inFile.open("/usr/share/lib/dict/words");
         if (inFile.fail())
         {
            cout << "Error opening file - quit\n";
            return;
         }
         string word;
         while (inFile >> word)
         {
            sort(word.begin(), word.end());
            if (word == inputPhrase){
                int max = sizeof(anagramList)/sizeof(anagramList[0]);
                max++;
                string* temp = new string[max]; 
                for (int i=0; i<max; i++) {
                    if(i == max-1){
                         temp[i] = word;
                         
                    }else{
                        temp[i] = anagramList[i];       
                    }
                }
                delete [] anagramList;              
                anagramList = temp;                 
            }
         }
         inFile.close();
      }
};


int main()
{
    string in;
    cout << "Please enter a phrase: ";
    cin >> in;
    Anagrams anag(anag);
    anag.findAnagrams();

    return 0;
}
