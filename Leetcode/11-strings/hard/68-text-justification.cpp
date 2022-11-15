/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int currWidth = 0;
        int i = 0;
        int totalWords = 0;

        vector<string> result;

        while(i < words.size()) {

            if(currWidth + words[i].length() <= maxWidth) {
                currWidth += words[i].length();
                currWidth++; // for space after word
                totalWords++;
            } 
            
            else {

                // justify text from i-totalwords to i-1
                currWidth--; // removing the space after last word of curr sentence

                int extraWidth = maxWidth - currWidth;
                int start = i - totalWords;
                int end = i - 1;

                int equalSpacesCount = 0;
                int leftoverSpacesCount = 0;

                if(totalWords - 1 > 0) {
                    equalSpacesCount = extraWidth / (totalWords - 1);
                    leftoverSpacesCount = extraWidth % (totalWords - 1);
                }

                string equalSpaces(equalSpacesCount, ' ');
                string sentence = "";
                
                for(int idx=start; idx<end; idx++) {
                    sentence += words[idx];
                    sentence += " ";
                    sentence += equalSpaces;
                    if(leftoverSpacesCount > 0) {
                        sentence += " ";
                        leftoverSpacesCount--;
                    }
                }

                sentence += words[end];

                // edge case
                if(sentence.length() < maxWidth) {
                    string endSpaces(maxWidth - sentence.length(), ' ');
                    sentence += endSpaces;
                }

                result.push_back(sentence);

                // reset values for next sentence
                currWidth = words[i].length();
                currWidth++; // for space
                totalWords = 1;

            }

            i++;

        }

        // last line should be left justified
        int start = i - totalWords;
        int end = i - 1;
        currWidth--; // removing the space after last word of curr sentence
        int leftoverSpacesCount = maxWidth - currWidth;

        string sentence = "";
        for(int idx=start; idx<end; idx++) {
            sentence += words[idx];
            sentence += " ";
        }
        sentence += words[end];
        
        string endSpaces(leftoverSpacesCount, ' ');
        sentence += endSpaces;

        result.push_back(sentence);

        return result;
    }
};