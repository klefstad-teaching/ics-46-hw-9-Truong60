#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg)
{
    cout << word1 << " " << msg << endl;
    cout << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{   
    int d_counter = 0; 
    int str1INDEX = 0, str2INDEX = 0;
    for (; str1INDEX < str1.length() && str2INDEX < str2.length(); str1INDEX++, str2INDEX++){
        if (str1[str1INDEX] == str2[str2INDEX]){
            str1INDEX++;
            str2INDEX++;
        } else{
            d_counter++;
            if (d_counter > d){
                return false;
            }
            if (str1.length() > str2.length()){
                str2INDEX++;
            } else if (str2.length() > str1.length()){
                str1INDEX++;
            } else{
                str1INDEX++;
                str2INDEX++;
            }
        }
    }
    if (str1INDEX < str1.length()){
        d_counter += str1.length() - str1INDEX;
    } else if (str2INDEX < str2.length()){
        d_counter += str2.length() - str2INDEX;
    }
    return d_counter == d;
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