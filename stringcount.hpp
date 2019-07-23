///////////////////////////////////////////////////////////////////////////////
// project2.hpp
//
// Implementations of algorithms for counting vowels, longest "oreo" problem,
// and longest repeated substring problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cctype>
#include <fstream>
#include <optional>
#include <random>
#include <string>

std::optional<std::string> read_text_file(const std::string& path) {

  std::string result;

  std::ifstream f(path);
  if (!f) {
    return std::nullopt;
  }

  for (char ch; f.get(ch);) {
    result.push_back(ch);
  }

  return result;
}

std::string random_string(unsigned seed, size_t size) {

  assert(size >= 0);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist(0x00, 0xFF);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}
unsigned vowel_count(const std::string& s) {
    if(s.length()==0){
        return 0;
    }

   int vowel_count = 0;
    for (int i = 0;i<s.length();i++){
        if(s[i]=='a'|| s[i] =='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u' ||s[i]=='A'|| s[i] =='E'|| s[i]=='I'||s[i]=='O'||s[i]=='U'){
            ++vowel_count;
        }
    }
  return vowel_count;
}
std::string longest_oreo(const std::string& s) {
  assert(s.size() > 0);

  if(s.length()==1 || s[0] == s[s.length()-1]){
      return s;
  }
  std:: string longest_o ="";
  std:: string current_o = "";
    int n = s.length()-1;
    for(int i = 0;i<n;i++){
        for(int j = n;j>i;j--){
            current_o="";
            if(s[i]==s[j]){
                for(int a = i;a<=j;a++){
                    current_o+=s[a];
                }
                if(current_o.length()>longest_o.length()){
                    longest_o = current_o;
                }
            }
        }
    }
  return longest_o;
}
std::string longest_repeated_substring(const std::string& s) {
  assert(s.size() > 0);

  if(s.length()==1){
      return "";
  }

  std::string substring = "";
  std::string longest_sub = "";

  int a = 0;
  int b = 0;
  for(int i = 0; i <s.length()-1; i++){
      for(int j = i+1; j<s.length(); j++){
          substring = "";
          a=i;
          b = j;
          if(substring.length()==0 && s[a]==s[b]){
              substring+=s[a];
              ++a;
              ++b;
          }

          while(s[a]==s[b] && s[a-1]==s[b-1] && b<s.length()){
              substring+=s[a];
              ++a;
              ++b;
          }

          if(longest_sub.length()<substring.length()){
              longest_sub = substring;
          }
      }
  }
  return longest_sub;
}
