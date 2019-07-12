
///////////////////////////////////////////////////////////////////////////////
// unittest.cpp
//
// Unit tests for the functionality declared in stringcount.hpp .
///////////////////////////////////////////////////////////////////////////////

#include <string>

#include "gtest/gtest.h"

#include "stringcount.hpp"

const std::string a("a"),
                  cats_and_dogs("cats and dogs"),
                  hakuna_matata("hakuna matata");

auto words = read_text_file("words.txt"),
     warandpeace = read_text_file("warandpeace.txt");

TEST(read_text_file, read_text_file) {
  ASSERT_TRUE(words);
  EXPECT_EQ(971578, words->size());

  ASSERT_TRUE(warandpeace);
  EXPECT_EQ(3359550, warandpeace->size());
}

TEST(vowel_count, vowel_count) {
  EXPECT_EQ(0, vowel_count(""));
  EXPECT_EQ(1, vowel_count(a));
  EXPECT_EQ(3, vowel_count(cats_and_dogs));
  EXPECT_EQ(6, vowel_count(hakuna_matata));
  EXPECT_EQ(4, vowel_count("AaEe"));

  ASSERT_TRUE(words);
  ASSERT_TRUE(warandpeace);
  EXPECT_EQ(304513, vowel_count(*words));
  EXPECT_EQ(943031, vowel_count(*warandpeace));
}

TEST(longest_oreo, longest_oreo) {
  EXPECT_EQ("a", longest_oreo(a));
  EXPECT_EQ("s and dogs", longest_oreo(cats_and_dogs));
  EXPECT_EQ("akuna matata", longest_oreo(hakuna_matata));
}

TEST(longest_repeated_substring, longest_repeated_substring) {
  EXPECT_EQ("", longest_repeated_substring(a));
  EXPECT_EQ("a", longest_repeated_substring(cats_and_dogs));
  EXPECT_EQ("ata", longest_repeated_substring(hakuna_matata));  
}
