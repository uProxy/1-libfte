#include "gtest/gtest.h"

#include "ffx/aes_ecb.h"

// Test vector from http://csrc.nist.gov/archive/aes/rijndael/rijndael-vals.zip

TEST(AES_ECB, Encrypt1) {
  std::string key = "00000000000000000000000000000000";
  uint8_t base = 16;
  mpz_class plaintext = mpz_class("00000000000000000000000000000000",base);
  uint32_t plaintext_len = 128;
  mpz_class ciphertext;
  ffx::AesEcbEncrypt(key, plaintext, plaintext_len, &ciphertext);
  EXPECT_EQ(ciphertext.get_str(base), "66e94bd4ef8a2c3b884cfa59ca342b2e");
}

TEST(AES_ECB, Encrypt2) {
  std::string key = "000102030405060708090A0B0C0D0E0F";
  uint8_t base = 16;
  mpz_class plaintext = mpz_class("000102030405060708090A0B0C0D0E0F",base);
  uint32_t plaintext_len = 128;
  mpz_class ciphertext;
  ffx::AesEcbEncrypt(key, plaintext, plaintext_len, &ciphertext);
  EXPECT_EQ(ciphertext.get_str(base), "a940bb5416ef045f1c39458c653ea5a");
}
