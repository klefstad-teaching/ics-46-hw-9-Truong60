#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg)
{
    cout << word1 << " " << msg << endl;
    cout << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    if (str1.length() == str2.length()){
        int d_counter = 0;
        for (int i = 0; i < str1.length(); i++){
            if (str1[i] != str2[i]){
                d_counter += 1;
            }
            if (d_counter > d){
                return false;
            }
        }
        return d_counter == d;   
    } else{
        int d_counter2 = 0;
        for (int str1INDEX = 0, str2INDEX = 0; str1INDEX < str1.length() && str2INDEX < str2.length(); str1INDEX++, str2INDEX++){
            if (str1.length() > str2.length()){
                str2INDEX -= 1;
            } else if (str2.length() > str1.length()){
                str1INDEX -= 1;
            }
        }
        return d_counter2;
    }
}

bool is_adjacent(const string& word1, const string& word2)
{   
    int d_diff = 1;
    return edit_distance_within(word1, word2, d_diff);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){}
void load_words(set<string> & word_list, const string& file_name){}
void print_word_ladder(const vector<string>& ladder)
{
    for (int i = 0; i < ladder.size(); i++){
        cout << ladder[i] << " ";
    }
}
void verify_word_ladder(){}