#include <iostream>
#include <algorithm>  
#include <fstream>
using namespace std;

class Anagrams {
   protected:
      string inputPhrase;
      
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
