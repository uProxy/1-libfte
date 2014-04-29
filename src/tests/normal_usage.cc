#include "gtest/gtest.h"
#include "ranker.h"
#include "dfas.h"

//0

TEST(NormalUsage, Test1) {
  ranker rankerObj(VALID_DFA_1, 16);
  std::string X = rankerObj.unrank(0);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(0, C);
}

TEST(NormalUsage, Test2) {
  ranker rankerObj(VALID_DFA_2, 16);
  std::string X = rankerObj.unrank(0);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(0, C);
}

TEST(NormalUsage, Test3) {
  ranker rankerObj(VALID_DFA_3, 16);
  std::string X = rankerObj.unrank(0);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(0, C);
}

TEST(NormalUsage, Test4) {
  ranker rankerObj(VALID_DFA_4, 16);
  std::string X = rankerObj.unrank(0);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(0, C);
}

TEST(NormalUsage, Test5) {
  ranker rankerObj(VALID_DFA_5, 16);
  std::string X = rankerObj.unrank(0);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(0, C);
}

//capacity

TEST(NormalUsage, Test6) {
  ranker rankerObj(VALID_DFA_1, 16);
  mpz_class words_in_language = rankerObj.getNumWordsInLanguage( 0, 16 );
  std::string X = rankerObj.unrank(words_in_language-1);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(words_in_language-1, C);
}

TEST(NormalUsage, Test7) {
  ranker rankerObj(VALID_DFA_2, 16);
  mpz_class words_in_language = rankerObj.getNumWordsInLanguage( 0, 16 );
  std::string X = rankerObj.unrank(words_in_language-1);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(words_in_language-1, C);
}

TEST(NormalUsage, Test8) {
  ranker rankerObj(VALID_DFA_3, 16);
  mpz_class words_in_language = rankerObj.getNumWordsInLanguage( 0, 16 );
  std::string X = rankerObj.unrank(words_in_language-1);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(words_in_language-1, C);
}

TEST(NormalUsage, Test9) {
  ranker rankerObj(VALID_DFA_4, 16);
  mpz_class words_in_language = rankerObj.getNumWordsInLanguage( 0, 16 );
  std::string X = rankerObj.unrank(words_in_language-1);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(words_in_language-1, C);
}

TEST(NormalUsage, Test10) {
  ranker rankerObj(VALID_DFA_5, 16);
  mpz_class words_in_language = rankerObj.getNumWordsInLanguage( 0, 16 );
  std::string X = rankerObj.unrank(words_in_language-1);
  mpz_class   C = rankerObj.rank(X);
  EXPECT_EQ(words_in_language-1, C);
}