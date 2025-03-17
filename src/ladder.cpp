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
    size_t str1INDEX = 0, str2INDEX = 0;
    if (str1 == str2){
        return true;
    }
    while (str1INDEX < str1.length() && str2INDEX < str2.length()){
        if (str1[str1INDEX] == str2[str2INDEX]){
            str1INDEX++;
            str2INDEX++;
        } else{
            d_counter++;
            if (d_counter > d){
                return false;
            }
            if (str1.length() > str2.length()){
                str1INDEX++;
            } else if (str2.length() > str1.length()){
                str2INDEX++;
            } else{
                str1INDEX++;
                str2INDEX++;
            }
        }
    }
    if (str2.length() < str1.length()){
        d_counter += str1.length() - str1INDEX;
    } else if (str1.length() < str2.length()){
        d_counter += str2.length() - str2INDEX;
    }
    return d_counter == d;
}

bool is_adjacent(const string& word1, const string& word2)
{   
    int d_diff = 1;
    return edit_distance_within(word1, word2, d_diff);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{   
    vector<string> empty;
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (string word : word_list){
            if (is_adjacent(last_word, word)){
                if (visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                } 
            }
        }
    }
    return empty;
}
void load_words(set<string> & word_list, const string& file_name)
{
    ifstream file_to_copy(file_name);
    string word;
    while (file_to_copy >> word){
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder)
{
    for (size_t i = 0; i < ladder.size(); i++){
        cout << "Word ladder found:" << ladder[i] << " ";
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder()
{
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}