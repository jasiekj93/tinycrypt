/**
 * @file Runner.cpp
 * @author Adrian Szczepanski
 * @date 2025-11-27
 */

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness_c.h>

TEST_GROUP_C_WRAPPER(AesTest)
{
};

TEST_C_WRAPPER(AesTest, test_1);
TEST_C_WRAPPER(AesTest, test_2);
TEST_C_WRAPPER(AesTest, test_3);
TEST_C_WRAPPER(AesTest, test_4);

TEST_GROUP_C_WRAPPER(CbcTest)
{
};

TEST_C_WRAPPER(CbcTest, test_1_and_2);

TEST_GROUP_C_WRAPPER(CcmTest)
{
};

TEST_C_WRAPPER(CcmTest, test_vector_1);
TEST_C_WRAPPER(CcmTest, test_vector_2);
TEST_C_WRAPPER(CcmTest, test_vector_3);
TEST_C_WRAPPER(CcmTest, test_vector_4);
TEST_C_WRAPPER(CcmTest, test_vector_5);
TEST_C_WRAPPER(CcmTest, test_vector_6);
TEST_C_WRAPPER(CcmTest, test_vector_7);
TEST_C_WRAPPER(CcmTest, test_vector_8);

TEST_GROUP_C_WRAPPER(CmacTest)
{
    TEST_GROUP_C_SETUP_WRAPPER(CmacTest);
};

TEST_C_WRAPPER(CmacTest, verify_gf_2_128_double);
TEST_C_WRAPPER(CmacTest, verify_cmac_null_msg);
TEST_C_WRAPPER(CmacTest, verify_cmac_1_block_msg);
TEST_C_WRAPPER(CmacTest, verify_cmac_320_bit_msg);
TEST_C_WRAPPER(CmacTest, verify_cmac_512_bit_msg);

TEST_GROUP_C_WRAPPER(CtrTest)
{
};

TEST_C_WRAPPER(CtrTest, test_1_and_2);

TEST_GROUP_C_WRAPPER(CtrPrngTest)
{
};

TEST_C_WRAPPER(CtrPrngTest, executePrngTestVectors);
TEST_C_WRAPPER(CtrPrngTest, testReseed);
TEST_C_WRAPPER(CtrPrngTest, testUninstantiate);
TEST_C_WRAPPER(CtrPrngTest, testRobustness);

TEST_GROUP_C_WRAPPER(EccDhTest)
{
    TEST_GROUP_C_SETUP_WRAPPER(EccDhTest);
};

TEST_C_WRAPPER(EccDhTest, cavp_ecdh);
TEST_C_WRAPPER(EccDhTest, cavp_keygen);
TEST_C_WRAPPER(EccDhTest, cavp_pkv);
TEST_C_WRAPPER(EccDhTest, montecarlo_ecdh);

TEST_GROUP_C_WRAPPER(EccDsaTest)
{
    TEST_GROUP_C_SETUP_WRAPPER(EccDsaTest);
};

TEST_C_WRAPPER(EccDsaTest, cavp_sign);
TEST_C_WRAPPER(EccDsaTest, cavp_verify);
TEST_C_WRAPPER(EccDsaTest, montecarlo_signverify);

TEST_GROUP_C_WRAPPER(HmacPrngTest)
{
};

TEST_C_WRAPPER(HmacPrngTest, test_1);
TEST_C_WRAPPER(HmacPrngTest, test_2);
TEST_C_WRAPPER(HmacPrngTest, test_3);
TEST_C_WRAPPER(HmacPrngTest, test_4);
TEST_C_WRAPPER(HmacPrngTest, test_5);
TEST_C_WRAPPER(HmacPrngTest, test_6);
TEST_C_WRAPPER(HmacPrngTest, test_7);
TEST_C_WRAPPER(HmacPrngTest, test_8);
TEST_C_WRAPPER(HmacPrngTest, test_9);
TEST_C_WRAPPER(HmacPrngTest, test_10);
TEST_C_WRAPPER(HmacPrngTest, test_11);
TEST_C_WRAPPER(HmacPrngTest, test_12);
TEST_C_WRAPPER(HmacPrngTest, test_13);
TEST_C_WRAPPER(HmacPrngTest, test_14);
TEST_C_WRAPPER(HmacPrngTest, test_15);
TEST_C_WRAPPER(HmacPrngTest, test_16);
TEST_C_WRAPPER(HmacPrngTest, test_17);
TEST_C_WRAPPER(HmacPrngTest, test_18);
TEST_C_WRAPPER(HmacPrngTest, test_19);
TEST_C_WRAPPER(HmacPrngTest, test_20);
TEST_C_WRAPPER(HmacPrngTest, test_21);
TEST_C_WRAPPER(HmacPrngTest, test_22);
TEST_C_WRAPPER(HmacPrngTest, test_23);
TEST_C_WRAPPER(HmacPrngTest, test_24);
TEST_C_WRAPPER(HmacPrngTest, test_25);
TEST_C_WRAPPER(HmacPrngTest, test_26);
TEST_C_WRAPPER(HmacPrngTest, test_27);
TEST_C_WRAPPER(HmacPrngTest, test_28);
TEST_C_WRAPPER(HmacPrngTest, test_29);
TEST_C_WRAPPER(HmacPrngTest, test_30);
TEST_C_WRAPPER(HmacPrngTest, test_31);
TEST_C_WRAPPER(HmacPrngTest, test_32);
TEST_C_WRAPPER(HmacPrngTest, test_33);
TEST_C_WRAPPER(HmacPrngTest, test_34);
TEST_C_WRAPPER(HmacPrngTest, test_35);
TEST_C_WRAPPER(HmacPrngTest, test_36);
TEST_C_WRAPPER(HmacPrngTest, test_37);
TEST_C_WRAPPER(HmacPrngTest, test_38);
TEST_C_WRAPPER(HmacPrngTest, test_39);
TEST_C_WRAPPER(HmacPrngTest, test_40);
TEST_C_WRAPPER(HmacPrngTest, test_41);
TEST_C_WRAPPER(HmacPrngTest, test_42);
TEST_C_WRAPPER(HmacPrngTest, test_43);
TEST_C_WRAPPER(HmacPrngTest, test_44);
TEST_C_WRAPPER(HmacPrngTest, test_45);
TEST_C_WRAPPER(HmacPrngTest, test_46);
TEST_C_WRAPPER(HmacPrngTest, test_47);
TEST_C_WRAPPER(HmacPrngTest, test_48);
TEST_C_WRAPPER(HmacPrngTest, test_49);
TEST_C_WRAPPER(HmacPrngTest, test_50);
TEST_C_WRAPPER(HmacPrngTest, test_51);
TEST_C_WRAPPER(HmacPrngTest, test_52);
TEST_C_WRAPPER(HmacPrngTest, test_53);
TEST_C_WRAPPER(HmacPrngTest, test_54);
TEST_C_WRAPPER(HmacPrngTest, test_55);
TEST_C_WRAPPER(HmacPrngTest, test_56);
TEST_C_WRAPPER(HmacPrngTest, test_57);
TEST_C_WRAPPER(HmacPrngTest, test_58);
TEST_C_WRAPPER(HmacPrngTest, test_59);
TEST_C_WRAPPER(HmacPrngTest, test_60);
TEST_C_WRAPPER(HmacPrngTest, test_61);
TEST_C_WRAPPER(HmacPrngTest, test_62);
TEST_C_WRAPPER(HmacPrngTest, test_63);
TEST_C_WRAPPER(HmacPrngTest, test_64);
TEST_C_WRAPPER(HmacPrngTest, test_65);
TEST_C_WRAPPER(HmacPrngTest, test_66);
TEST_C_WRAPPER(HmacPrngTest, test_67);
TEST_C_WRAPPER(HmacPrngTest, test_68);
TEST_C_WRAPPER(HmacPrngTest, test_69);
TEST_C_WRAPPER(HmacPrngTest, test_70);
TEST_C_WRAPPER(HmacPrngTest, test_71);
TEST_C_WRAPPER(HmacPrngTest, test_72);
TEST_C_WRAPPER(HmacPrngTest, test_73);
TEST_C_WRAPPER(HmacPrngTest, test_74);
TEST_C_WRAPPER(HmacPrngTest, test_75);
TEST_C_WRAPPER(HmacPrngTest, test_76);
TEST_C_WRAPPER(HmacPrngTest, test_77);
TEST_C_WRAPPER(HmacPrngTest, test_78);
TEST_C_WRAPPER(HmacPrngTest, test_79);
TEST_C_WRAPPER(HmacPrngTest, test_80);
TEST_C_WRAPPER(HmacPrngTest, test_81);
TEST_C_WRAPPER(HmacPrngTest, test_82);
TEST_C_WRAPPER(HmacPrngTest, test_83);
TEST_C_WRAPPER(HmacPrngTest, test_84);
TEST_C_WRAPPER(HmacPrngTest, test_85);
TEST_C_WRAPPER(HmacPrngTest, test_86);
TEST_C_WRAPPER(HmacPrngTest, test_87);
TEST_C_WRAPPER(HmacPrngTest, test_88);
TEST_C_WRAPPER(HmacPrngTest, test_89);
TEST_C_WRAPPER(HmacPrngTest, test_90);
TEST_C_WRAPPER(HmacPrngTest, test_91);
TEST_C_WRAPPER(HmacPrngTest, test_92);
TEST_C_WRAPPER(HmacPrngTest, test_93);
TEST_C_WRAPPER(HmacPrngTest, test_94);
TEST_C_WRAPPER(HmacPrngTest, test_95);
TEST_C_WRAPPER(HmacPrngTest, test_96);
TEST_C_WRAPPER(HmacPrngTest, test_97);
TEST_C_WRAPPER(HmacPrngTest, test_98);
TEST_C_WRAPPER(HmacPrngTest, test_99);
TEST_C_WRAPPER(HmacPrngTest, test_100);
TEST_C_WRAPPER(HmacPrngTest, test_101);
TEST_C_WRAPPER(HmacPrngTest, test_102);
TEST_C_WRAPPER(HmacPrngTest, test_103);
TEST_C_WRAPPER(HmacPrngTest, test_104);
TEST_C_WRAPPER(HmacPrngTest, test_105);
TEST_C_WRAPPER(HmacPrngTest, test_106);
TEST_C_WRAPPER(HmacPrngTest, test_107);
TEST_C_WRAPPER(HmacPrngTest, test_108);
TEST_C_WRAPPER(HmacPrngTest, test_109);
TEST_C_WRAPPER(HmacPrngTest, test_110);
TEST_C_WRAPPER(HmacPrngTest, test_111);
TEST_C_WRAPPER(HmacPrngTest, test_112);
TEST_C_WRAPPER(HmacPrngTest, test_113);
TEST_C_WRAPPER(HmacPrngTest, test_114);
TEST_C_WRAPPER(HmacPrngTest, test_115);
TEST_C_WRAPPER(HmacPrngTest, test_116);
TEST_C_WRAPPER(HmacPrngTest, test_117);
TEST_C_WRAPPER(HmacPrngTest, test_118);
TEST_C_WRAPPER(HmacPrngTest, test_119);
TEST_C_WRAPPER(HmacPrngTest, test_120);

TEST_GROUP_C_WRAPPER(HmacTest)
{
};

TEST_C_WRAPPER(HmacTest, test_1);
TEST_C_WRAPPER(HmacTest, test_2);
TEST_C_WRAPPER(HmacTest, test_3);
TEST_C_WRAPPER(HmacTest, test_4);
TEST_C_WRAPPER(HmacTest, test_5);
TEST_C_WRAPPER(HmacTest, test_6);
TEST_C_WRAPPER(HmacTest, test_7);

TEST_GROUP_C_WRAPPER(Sha256Test)
{
};

TEST_C_WRAPPER(Sha256Test, test_1);
TEST_C_WRAPPER(Sha256Test, test_2);
TEST_C_WRAPPER(Sha256Test, test_3);
TEST_C_WRAPPER(Sha256Test, test_4);
TEST_C_WRAPPER(Sha256Test, test_5);
TEST_C_WRAPPER(Sha256Test, test_6);
TEST_C_WRAPPER(Sha256Test, test_7);
TEST_C_WRAPPER(Sha256Test, test_8);
TEST_C_WRAPPER(Sha256Test, test_9);
TEST_C_WRAPPER(Sha256Test, test_10);
TEST_C_WRAPPER(Sha256Test, test_11);
TEST_C_WRAPPER(Sha256Test, test_12);
TEST_C_WRAPPER(Sha256Test, test_13);
TEST_C_WRAPPER(Sha256Test, test_14);

int main(int argc, char* argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
