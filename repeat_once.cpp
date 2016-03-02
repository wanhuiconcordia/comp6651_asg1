#include "repeat_once.h"
#include <iostream>
int repeat_once(std::string& str){
    int strLen = str.length();
    char A[strLen];
    str.copy(A, strLen);
    char prefixArray[strLen];
    int n = 0;
    for(int c = 2; c <= strLen; c += 2){
        n += m_repeat_once(prefixArray, 0, A, 0, strLen - 1, c, c);
    }
    return n;
}


int m_repeat_once(char* prefix, int prefixSize, char* A, int start, int end, int count, int c){
    int n = 0;
    int half_C = c / 2;
    if(prefixSize > half_C){
        if(prefix[prefixSize - half_C - 1] != prefix[prefixSize - 1]){
            return 0;
        }
    }

    if(count == 0){
        if(prefix[half_C - 1] == prefix[c - 1]){
            n++;
        }
        return n;
    }

    for(int i = start; i < end - count + 2; i++){
        prefix[prefixSize] = A[i];
        n += m_repeat_once(prefix, prefixSize + 1, A, i + 1, end, count - 1, c);
    }
    return n;
}



typedef struct{
    char c;
    int count;
} LetterCount;

typedef struct{
    LetterCount* lc;
    int size;
} LetterGroup;


LetterGroup calcLetterGroup(char* A, int& size){
    LetterGroup group;
    int B[26];
    std::fill(B, B + 26, 0);
    for(auto i = 0; i < size; i++){
        B[A[i] - 'a'] += 1;
    }

    int validCharCount = 0;
    for(auto i = 0; i < 26; i++){
        if(B[i] > 1){
            validCharCount++;
        }
    }

    std::cout << "valid char:" << validCharCount << std::endl;
    group.lc = new LetterCount[validCharCount];
    group.size = validCharCount;

    int index = 0;
    for(auto i = 0; i < 26; i++){
        if(B[i] > 1){
            group.lc[index].c = i + 'a';
            group.lc[index].count = B[i];
            index++;
        }
    }
    int p = 0;
    for(auto i = 0; i < size; i++){
        if(B[A[i] - 'a'] > 1){
            A[p++] = A[i];
        }
    }

    size = p;
    return group;
}
