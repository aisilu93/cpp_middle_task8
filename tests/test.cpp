#include "../include/RefactorTool.h"
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

TEST(BasicCheck, VirtualCheck) {
    std::filesystem::path input = "../tests/tests_data/test1.cpp";
    std::filesystem::path tmp = "../tests/tests_data/tmp/test1.cpp";
    std::filesystem::path expected = "../tests/tests_data/test1_ref.cpp";
    std::cout << std::filesystem::current_path() << '\n';
    std::cout << std::filesystem::absolute(input) << '\n';
    std::cout << std::filesystem::exists(input) << '\n';

    std::filesystem::copy_file(input, tmp, std::filesystem::copy_options::overwrite_existing);

    auto cmd = "./refactor_tool " + tmp.string();
    int ret = system(cmd.c_str());

    EXPECT_EQ(ret, 0);
    std::ifstream tmpFile(tmp);
    std::ifstream expectedFile(expected);

    std::string res((std::istreambuf_iterator<char>(tmpFile)), std::istreambuf_iterator<char>());
    std::string exp((std::istreambuf_iterator<char>(expectedFile)), std::istreambuf_iterator<char>());
    EXPECT_EQ(res, exp);
    std::filesystem::remove(tmp);
}

TEST(BasicCheck, OverrideCheck) {
    std::filesystem::path input = "../tests/tests_data/test2.cpp";
    std::filesystem::path tmp = "../tests/tests_data/tmp/test2.cpp";
    std::filesystem::path expected = "../tests/tests_data/test2_ref.cpp";

    std::filesystem::copy_file(input, tmp, std::filesystem::copy_options::overwrite_existing);

    auto cmd = "./refactor_tool " + tmp.string();
    int ret = system(cmd.c_str());

    EXPECT_EQ(ret, 0);
    std::ifstream tmpFile(tmp);
    std::ifstream expectedFile(expected);

    std::string res((std::istreambuf_iterator<char>(tmpFile)), std::istreambuf_iterator<char>());
    std::string exp((std::istreambuf_iterator<char>(expectedFile)), std::istreambuf_iterator<char>());
    EXPECT_EQ(res, exp);
    std::filesystem::remove(tmp);
}

TEST(BasicCheck, RefCheck) {
    std::filesystem::path input = "../tests/tests_data/test3.cpp";
    std::filesystem::path tmp = "../tests/tests_data/tmp/test3.cpp";
    std::filesystem::path expected = "../tests/tests_data/test3_ref.cpp";

    std::filesystem::copy_file(input, tmp, std::filesystem::copy_options::overwrite_existing);

    auto cmd = "./refactor_tool " + tmp.string();
    int ret = system(cmd.c_str());

    EXPECT_EQ(ret, 0);
    std::ifstream tmpFile(tmp);
    std::ifstream expectedFile(expected);

    std::string res((std::istreambuf_iterator<char>(tmpFile)), std::istreambuf_iterator<char>());
    std::string exp((std::istreambuf_iterator<char>(expectedFile)), std::istreambuf_iterator<char>());
    EXPECT_EQ(res, exp);
    std::filesystem::remove(tmp);
}