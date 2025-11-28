/**
 * @file Cbc.test.cpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <etl/string.h>

#include <tinycryptpp/aes/Cbc.hpp>

#include <CppUTest/TestHarness.h>

using namespace tinycryptpp::aes;
using namespace tinycryptpp::aes::cbc;

TEST_GROUP(AesCbcTest)
{
};

TEST(AesCbcTest, encrypt_and_Decrypt)
{
    Key key = {
        0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
        0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
    };

    Iv iv = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };

    etl::array<uint8_t, 128> encryptBuffer = { 0 };
    etl::array<uint8_t, 128> decryptBuffer = { 0 };

    etl::string<64> plaintext = "This is a test message for AES CBC mode encryption!";
    etl::span<const uint8_t> plaintextSpan(
        reinterpret_cast<const uint8_t*>(plaintext.data()), plaintext.max_size());

    Encrypt encryptor(key, iv, { encryptBuffer.data(), encryptBuffer.size() });
    auto encryptResult = encryptor(plaintextSpan);

    CHECK_TRUE(encryptResult.has_value());

    Decrypt decryptor(key, { decryptBuffer.data(), decryptBuffer.size() });
    auto decryptResult = decryptor( { encryptBuffer.data(), encryptResult->size() } );

    CHECK_TRUE(decryptResult.has_value());
    STRCMP_EQUAL(plaintext.data(), reinterpret_cast<const char*>(decryptResult->data()));
}

TEST(AesCbcTest, cleanAfterUse)
{
    etl::array<uint8_t, 128> encryptBuffer = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    {
        Key key = {
            0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
            0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
        };

        Iv iv = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
        };

        etl::string<64> plaintext = "This is a test message for AES CBC mode encryption!";
        etl::span<const uint8_t> plaintextSpan(
            reinterpret_cast<const uint8_t*>(plaintext.data()), plaintext.max_size());

        Encrypt encryptor(key, iv, { encryptBuffer.data(), encryptBuffer.size() });
        auto encryptResult = encryptor(plaintextSpan);

        CHECK_TRUE(encryptResult.has_value());
    }

    for (auto byte : encryptBuffer)
        CHECK_EQUAL(0, byte);
}