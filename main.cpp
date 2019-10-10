//filename: local_alignment.cpp
//to get a alignment score of two DNA string using local align with score matrix

#include <iostream>
#include <cstring>
#include <stack>

#define maxsize 10000

using namespace std;


int main()
{
    char *s = new char[maxsize];
    char *t = new char[maxsize];
    s =(char*)"CTCTTATATACTTACGCTTAACGCGCCATCCGTCGGTGTAAATCTCGCGCGCATACGCTCTGTAGATTCCCTTTGTTATCGAAAGCACAGTCGTGGGATGTAGCGCCACACCCCTTCTGTCTTCGGGCGCGGATCAAGTGTACGGGGCACCCTCGTCAGCTAGCTAATCTCTACACAGTACCCCTGCAGGTCCAGGAAACGCTGCCAGCCTATATAGCCATAGGACCCACCGCATTGTCGCCGGCCCCAACCCTGAACCGTGCGATCTTATAGCCGTCAGTTTCGCTAGCGCTGGTCATTCAGAGATGGTGTATAGTCATGATGTACTGCGATCCCAGCCGATTATCCGAATCCAAGCACTTTGGTAGACGTCCTAGGTGAGGGATAAACCCCCTCTGGCATTTCGAATAGCAGAAGTTATGGGACCGACAAGCAGCACTTAGGTGGCAGGCATGGTGAAGTTCTGCATCCATTCGATCACCACCCTGTAAATTTGGCCTGGTATTGATCGGTTCAAAGCAGAGTTCTCATCTAGGAGCAATTGGACTACGGGCGCCATCTCCAAATGATCCGCTACGGGAGGCATGGGCTAACAGTGAAGTCTAACAAAGTCCTAACGTCAGTAGCCGACAACGCACTACTCGTAGTTCGCCGACAAGGAGCGCTTCATCGCGGCCCTATGCGCCGGGGTCCCTTACCATATGCCATAGATTCCTCCGGCTCCTGCACAAGCTAACAGGTTGGAAAATCCTGCTTCGACTAGCAGAGTTGTTACCTAGCATGTTGGATGCCTGAACTGCTCAATCCACAATAGCGGATTCGGAGTTCTTAAATGCTTAAATGCAAGGCGGGCCCATCCAAGGCCATCCGAGTGGCGCGGCCTATTGTTGACGTATCCCGGCACGATACTCAATCACAGCCCGGTCGCACAAGGGCATGGAACAAGTAGGCCCGCCCCAGGAGTCGTGATGCAGCTGGCCAGGGAAAAATATATTAGGTAGTCGATTGCGAAGGGAGACATGAAGAGGGGCAGCTTCGTTGTTTTGAAATATACTTAGGGGTGAGGCACAAAGCCTCGTATACGCGGAGGACGACACGTAAGCGTCGTGACGTCTTTATGCAAAGACCGAGCTCGGAGATAGTATTCATGAAATTGGAGGTCTAGTTTGTTAGAAACATTGCCGCTAAGCTCGCACAGCAGTAAAAAGCACGGGTAGGAGTAAGGGAAGGAAAATTTTCTGCTAGGGAATGCTGCCCCCGGACCTCGGAAGGCGGTACAGGGCTGGGTGCTAGGGTAAGGCTCGCGTTGGAACGTGTACCCCAGTCTGCGTGCAATATATGGACCACCGCTTAGGCGCACGTACTAGAGATTAAGAATCAAGTCTCGTAAGTTACAGCTACGGTAGTTATACGTCTACGTGAAACATCTCCCCCCGAGAAAATTTGCACCGCGCTGTAGGTACAGGGGTAATGAGAGTAAATAGAAATCCTCTGCTGTAGCAGTACGTCGCCCTAGGTACCTAGTCATTCTACCCCGAAGTTCATCTCGAGCCCGCGCCGGTGTACTTCTTCTGATAAGTGGGGGCGTGCGGTCCAGAACCAGCTAGCGACAGTCCCACCATTCGGCCGCGTCAGACACTCGCTGTAGTCGTACCAGCGATTTCGTGAGCCGACGTCTACCTAACGGAACCTAGTCACCGAAATTCAGGTCTGCGTGAGGCGGACACACGCTTCAAAATTTAGTTGTAGCAGATACAAAGGATATATCACGCCTCACCCGAAGAGTGGACTAGGCGTTAGCTCACTGCCACATACACCGACAACCATTACTTGCATACCGCACTAGCGCTTCGAACGTATGTGAAAGTGTGCGCGTGTACAAGTCGAGCCTTGTTCCGGCACGCGGTAGGAAGATGGAGAAGAGCATCCCTTTCTACGGGCTATCTTCCCCTTGATCGCGTCTGTGTAAAGAGTAAAATTGGTGCATCGTGACCATCGACTAGGTTGCAAGTGTGATAGTCGTTATGTACAAGCCCGGAATTGTTGTGGAAACATAGAAGCTCTATTATATCATGCCTTGTTTCAATAAAGAGGCGGTTGTGGAGGGGCGCCGGACGAATGGTCACACTGGACCCCACATATGCCCCAGTATGCTAACTGGCTGGGGTAGTGGAACAAGTCCAATGCAGAGGACAAAGTCGCCACGGGCAGTACCTGAAATACCCGGTCCCCTACGACAGTATAACGTAAGATACGATGGATATCGAGGGGGTTATCTGCCGTTCTTAAACTAAGTCGGCGGATGTGAGCGGTGGCGCTATTGGATCGTGGAGATCCCAAAGTCACTTACTGTTAGTTAGCAAGTAACAATAAACGCCCCCAGCGCAACTTCGTAGCTAGAAGCCTGCTGTTCGCTAAATACGCTAGGACGCTTCCAGAGTGTAGGCCTAGTATAGTGCGCTTTGTAAAGCCAAGGGTCCAATTGAACGCCCAATGGTAGATCCCAAAACTCAAGTAACTGAAAGAGCGTGGAAAGAATCTATTGGTTAGTTATCTGCGAGGTATAGGTCCCACGTCTGGGACGTTGCGTGCATGGGGGGCCGGGGAACCGGCGCCTCCCGGAGCAACACCGCTACATATATCCGCTGCAAAATGCTAGGCTGTGGGACACAACAGGCTGCCGTATGGGTCAAATTGGAGGATAAGGCTAGAGTGTCTGTAGTAACTACCCATAGTACTCTTGCGATTAACAGTATAAGCGCTTTCGAATAGGATCGCGGGGGGGGTCTGGCCGGCTCCGGACGAGTCATAACACGTCTGCATATCTTAGGACGGCGGTTTGTATACCCGTTGTATGCAGCGTATTAGAAAGCCCCTCTCCTTCTCCTTGGTCCAGCCTAGCGTGTCCTCATCCAGGTTAAATCGCCCGACTCTAGTGCACCAGGCGTTCACCTACGTCGGGACACACGAGGCCGTGTTTTCCCCGCCGAAATCTACCCTTTTGGAATCGATTCGAGCAGTTATAAAACCTACCACCTAAATCGGACTATATGCTATCCATTGACGCACACTGTTAGTCTACAGCGAAGGCGCAATCCAAAACTGTGCCTGAACGGTACATTATTTACACATGATATCAAATTCAGAGGGCTTAGTCTTACCTTTCCTAAGTGTCGCATGTGGCTTATCTGAACGTTCTTTCGAAAGCACGGAAGTTTCACTATCGGCTCACACCTCAGTTACTATCTAAATGGCATCTGTGGGTTGTAGGGGTTGAGAAGTCGCAGGGAGGGTATCTTACTTCTTGTTCGCGAAACAAAGTGGTGTGGAAGCTGCCGAGGCATACGTCCCTCCATCAACGTGTGCTGTCACAGCCTTTAGACCCCCGCATGCCACAACTGGTTGGGGGGAAGGATAAGCAGGACACGTCACTCTTTGGCCGCAAAGGACCCGAAACATATCACGGGAACAAGAGCACGTCTTCTTAAATAGTTGGAAACAGCGATCATAGTGATTGGGCTAATTCGTAGTCCGGAAGTCTCAATGCTTGCGACACAGACTTCGATTGGGCTTTTTCTGATTATAGAGAAGTACACAAACGGCAGATGAAGGCGGCAGCCCCACTGTTCATCTTCCCTATTTAAACTCACAACCGGTGTGCCGAAAATGACGGGAACGGAGGGGCGATTTCCTAGACGCAGCGACGAAGCGAACCAGCAAATAATTTAAGCTCATATTCTTGGTGGCGCAACGCCAGTAGCAAGTTTATGAGTTCTAGGTCCGAGGGAGCTGGCACAACAATCAGCGACGCTCCGAACCATTTGCCGCTCGCGTAAGCCTTAACTGTTCTTGGCCGTTGTCGAATGACCCTAGGCCCGCAGGGAGACGAACCTATCATATTCTCCGCTGCATATAAATCGAGGACCAGTATTGGTGTAGTGCACGCAGATATCCTCGGCGAAGCGTGGAGAACTATCTGTCACGGCAGATACTCAATTTACGGTGGTCTTTAATCCCCCTCCTCTCGGCGATGGAGGCGACCCATTTCCGCAGTTACGAGGATCGTTTTAACCATTTTATATATCAAATGTGAGCAGCGACCATCGATCGCCCACGGGTACTGCTAACGGAGTGGTCCTTGGCACAGCATGAGACGGCGAACACTCCGAGAGTCAAGCCATCATTTCAAAATCGGTTTGGTAGGGCCCGATGTAACCTAGGTACTCGGCAGACGAGTTTGGAGTTTGCCACATGAAAATCGCAGGCTCCCCCGACCACTCGGGCAGGGACCGCTTAAGTCGCAAGGTATGGGCCTGAGTGCTCACCAATCATATGACACTTAGTAGAAAATGACCCCGGCTGCGAAGACTGAGTACCCTGCTGAATTATTGCGCGCGTTTGCTTAGTAGGCTAATGCGTCTGCTTCTGAAGGCAGAGTCTTGAGACCATGTGTGGGGGTCTTGATTAACGTACTCACGTATCGACCATGGGTTGTAATGTTCTGTACCACTCAGTAGATTGACCCCGTCGGAATGCCCCGCTGCAACTAACCCGATTTAGTTCGTGAAGGCTTGAAACTCAGTTTCCTAGCACCTTGTTCGTACACGTAGGTCCGAGTCGGGAGACCTATCATCGCCTTTCTCCCCTCAGTGTCTATCCGCACATGCTGAAGTGTGCATCCGATTAATACCAACTAAAGCCGCTGTGCAGTATTCCGCCTCCTGCGCGTCAACATCGATGAGGGGGCGCCAAGGCAAATGACCAGCCCAATTACAGCCAGTCGCAGGGGTCGGGACCATCTACTCCATTACGACTTCCAGTGGACAAGAAAGCGTATCTGACGAATCTGAGTGTACCACGTCAATGTACGCTCATATACGGGTGTTCCGCCTGAATTTATTCAAATATGTAGCGGAATCTTCGATGCGATCGCTTGTATAACTGCACCACGGCTAGACGTGATTGATGGGTTACGGTACGTTACCCTATACTACTGCTCGTGCAAGGGTTATCCTGGCCGTGATTCAGCTAGTAATCTTATTTGTTAAACATGCTATAAACAAATTAGCATGCTTCACACAGTTACGTCACTGCGACAGGGGGCACATACTCCCAGGGACCAGCGCATGATTCCAGGTTTCGCAGTAACGCGTGCCAAAAAGCCCGGTACAGCAGGTAAGTTCCTAACATACCATGTGGTGTAACGAAGACGCATAGGTAATGTGCCGCAGCGGTGGGACTAAAGTAGTGGTAACGCTCTGAGCGGAGTTTACCTAAGTAAAGCAGAGAACTTTCTAGCAATCCCACGTAGCCTTGATTCAAAGCTTAAGTTTGCCTTATTATTCCGACCCTACTATACGCGTAGGCGTCCCCCTCGCCACTCATGTCTTCGGACGCTCCCGATCGGACCAGAATGAGTAGTCCGTACTAAGGTCCTTACCAGCAGCCGGGCCCATAATAATGCGGTAACCCAGAATCTAGAGGGGCAGCAAACAATTTCCCTCAGCTTGTAGGTCGCATGACGACTAGGCGCGGTAACAGCCACCATCCCGCGGTATCGTGTTTAGCGTTTACCAGCCATTTGTATCTAATTAAGGTCGATCGTCACCGATTACTGCAAAGTGAGTAAGGGCACAGGCAGCCTACTTCCTGGCTGTTATACCACGGTCCTGAAAATAGCCATCCACATGGACCAGAAGCCCTTCTACGTTAAATGACTGTTTAGTATTCTATGCCCGCTGCTTAGTCCATGTCGATGCTTGGAGTTTCTCCATGTCATATGACAGGGCTTTCCAAGGTCCTTAGGGAGCCTTCTGTTTAGGTTGTAATGTAATTAAGCGTACGTATATAGTACGACAATCGATTTGCAGTAGCGTACGTCAGATCGGGTTGACGTTGGAGTTTTCGTTGGAGGACGAACCAAAGGAATCGTTATACGGGACGATAGCTTGCCAGTAGCCCTCTCCGGCTCATATAGTAGCACCCACAACACGCTCGTATGTGGTCGCAGGAGTCCTCACGCGGCTGCCACGTTCGGGAACATTGCGAGTCACCTATGTGGTCTCTGGACCCCTGCGCCGAAGATTGGTTCGTTACTGACAACGTACATCCCTATATACCCGCATTGGTCAATGCCACACTCTGAAGGAGGGTCGGGCGCGTAATAAATCCAGAATAGTACAGTCCGTACCTCACCAGGCTCATGAAGTAGGGTCCCACCAGGGAAGTGAATCAGGCCAACCCGCGGAGGTATGAAACTTATTTGGCACGGCGGGTAATCTAATTGATCCTCTCAATTTAGGGTAGATAGGATGGTTCCTTAGGTAGATGAAGCCAGTAGCCTAAACAAGCATTCCGTCCTTCTATGGTTGAGTCATGTCGTCTTATGGATTATATCTTATACCAGCGGGCTCGCCCGAGATTGGTGACCGGTAAGTGTCGCGTATTATTGCTGCGAACGCCTACGGATACGCATAAATTTGTCTAGCCTGGGCTAGATCGGCCTCATGTGAGGTAGCTGGGAACATGTACGACCCCGATGGTGCCCGGAGTATGTCAACAAGGTGTTGATGCAGCCGCATCCAAACGTGCTAGGACCTCCTACTCGTACCGTTGGAGGGGGTGGTTATTCGGGGAGAGTCTCGAACGTTTGATAGCCTGACGTGCATAGACACAATGGGCATACAACTTTGCCTATTCTCCGCGGTCCTGTGGACGCGCGCGGGTGCATACCGGACTCCTCATCCAAAAGGGGTCTACCTTATCGACTCCTCTGCAGAGCATAGTATCACCGCGATAGTAATTCGCGTAGGTCTCAACAAACACAGAGCACACATAGCACATACGGCCGTTTGAAACTGGTAGGTGCGAACATGTCAAACCAGAGTCACTACAGAACCGGTCAGCTCGAGTCTCAGAGCCTTCGACTATTCGGAGGCCTGAGCTGTGCTAGCGTTGCCGTAATCCCTACGTCCGTTTTATACCAGACTGCACAGCTAGTGTGCAGGTATGACAAATACGGTTTCAGTATTCGATCATCTTAATAAGTTAGCGGATAGATGGAACCAGACCTTGTCGGCGGCCACTACCCCTTTCGAATGATCAGAGATACACCACGTCCGCCATTCAAAAGGGTTAGATACAACGTACAGGCGCCACGTAGCCTTGGTTGGCACATCAGTCATAATGTGAATTGCCCGAATTGGTTACAAGTCTCCTTTGCGTGCTTGCTTATAGGTGTATGCGTCATTATAACCAACAACTGGAGCGACGGGGTGTCAGCCGGCAGATTCCCTATCCGCCGCTGCAGGCGTAGCAGCGTCCGTGAATTGAAAATGGTAACTAGACGAGTCGCATCGTGTCAGCCCAGCTTCCCATGTAATCCGGGCTAAGCGCTCGGTAAAACCGGAGCTTTAATTTTGGCAGGTTGGGTCTAGCAGTCCAACCGAACCATAAACTTGCATGTTCTTGCAAACTCAGTTCCTCCGACGAAGGTAATGAGGATTCACCTGCAGTCGCCGTGGTCGGTGTTGGTGGACGCTTATTGTTCAGCTCACGGAGTCCTTCTCGAACAGTTCCCTAAAGCCCGACACCGCTATCGACAACCTTTAGTACGAGACCGTTTGTCTTACCAGACTTTGTTGCCCGGGGGCAGTAGATCCGGCGTGTCCTGCGTCCTTGACTGTCCTATTAGCCTACTCCTGTATAAGGGGCGCGTCTGTGTATGCTTCGCGGTAGGTCTTTGGGTTCATTGACAAAATATTAGGGCATATGTGACGGATCGCGAATACCGTCAGAGATTAGTTATCTGGTTAGTGGCCGGCTACCTTAGAGGTCTGAAATTATATCATTTAAATTATAGTTGGTGACGTTTCTCTACACGCATAATGCATATCAGCAATTAGCGACACCCCCGGACCAGTTAGCCCTAAAAGGCGCGTGCAAGCGGCAATTGCGAAAGGGCTGAATCCCAGTTGGCAGCGGGGCGTCCAAAGCGCTCCGCCCCCGGAACATTTTATGGCGAACTGTACGCCCATAATACACTTCGTCGCGACGATTGGTACTTAGAAGAGTCTGGTCGTCAGGAGATGGCGTCTCACGAATGGCGATAAGTGGATCGTATAGCCACTCACAGTGGTGCAAAACTTGTCAGGGTCGGCTCTCTCAGTGCGACACGAGGAGGAGTAATCACTCGTCTTCGTAGGACTCGAAGGCCGAGAGAGATTAATCATTTGTCGGTACGCGGTGGAGCGGTTCACTCTACGCCACCGGCGCCGATCACTAAGAAGGGACCGAAGCTACCAGGCATATTAAGTAACATGCCGTTAAATGTATAGAGTTATCTCAAGACTCTGACTCTATACTGTGTCCGCATTCAATTCTCCTTAGTTGTCGTCCGTCATGCTTCTTCTCCAGGACATGAAGAAGACGCGACTTCATACACTAGTGATGTAGGCTACCGTCTAATCAGCGCTAATCCGTAATGGTTATGGTAGCCCCAG";
    t =(char*)"GCATTAAATCCAGAGATATCAAACCCTCCCTCGGCCAAGTTCTTGAATTGGGTTCCTTCAGGAAACTGATCGTCCGACCCCGTGGAGGGAAACCCATTCGCACGGTTGGGGAGTCTAACGGATCCTCTTATCACAGGCGATTAGTCACGATGGCATTCTTAGTAGGAAGCCAGTAGTCTAAACGAGCATTCCGTCCGCTCTATGTGTCCGAACTCTGTTCGGCCTATCGGCTTAATTTCATATGCGGGCGTCGTTGCCGAGTCTGTTGACGGGTAGAGTTGCGTATTATTGCACGAAGATCTACGAATACGCTAAAACTTTATCTACGGCCTGGGTTTGGTGACCTTCATGTGAGGTAGCTCGAGCATGTCGACCGCGACTGGTGCCTAGGTATGAACAATAAAGTGTTGCTACTTGCCGGAATCCAATCGTCCTAGTCACTCGTACTACGAACCCGCCTGTAAGTTGTGGTATTCGGACAACGATCCACAAATGTAGGAACAGCACTGCATCGTGCCATAGACATAACGGAGCATAAATTTCCCCAACTTGCCTGGTTCTGTTGACGCGCGCGGCGTCGTCAGTTGACTCTCATGCAAGAGGTCCACTTTGCTACGGTCTCTGCGGAGCAGTAGTACACCTCGATAGCGATTCGTGGAGGCTCGGTACAAAACATTGGAGCACACATAGTAGAATACGGCCGTACGGAAACTGTACGTGTCGAACGTCGCAAATAGGGTTAACCACCAAAATGCCGTTCTGACCTCAGAGCTGGGTCTTTCTGGAGGGCCATGATTGTGCATAGCCATCACCGTAATCCCTACGTCCGGTTTCAGCAGGACTGACCAGCTAATCATGTATGACGAATACGGTTTCAGCATGATATCCTAGCTAAGTTTAGGCGGACAAGAGGAACAACCTTACGGCGGCACTACCCCTTTTGAATGATCACTGATACACCACGATGCCGTTACTGTGAGGTCGGTAGCGGTAAGGCACACGTTTGGCGCTACGGCTGGCGAATCATTTCACCAATGTGAATTGACCCGAGATTAGTTACAACTCGTTTGCATACTTGTCTTACGGGGTATTGCTGTCCTTTAACAGTAAATGGAACGACACGAGCGTCGCACGCCAGACCTCTCTGTCTGCCGCTGCGGCTGTACCACGTCTTTGTGATTGAAGATGGGGCTAGACGGGACGCGTATGTCAGCACGAAGCCTTCCATTGTACATCTGTGCGTAGCGTCCGGTAGAATCGGAGCTTTATTTTGACAGGTGGAGATCTGCTACCCAACCCAACCTAAGCTCCCGGTTATCTTGCAGACTCGGATTCTTGCCCGACGAGGTGAATGCGGCTCATTGTCGTAGTCGCTGTTTTGGCGACGGGAACCTTTTTGCATCAGCTGGGAATCCTTGAACATTCCATAACAGCCCGCATCGCATCGAACATCTTTAAACCAGACCGTCTGCCTTACCAGGCTCTGTTGCCCGTGCGCAGTCAGACTCGCGGCGTCCTTCGGCCTTCGACCGGTACCTTCTAAGCCGCACTCCAATATCTATAGGTGGTGCGTTGCGACATGATTTCGCGGTGACCTACTGGGTTCGCTAACAAATATAAGGCCAATGCGACGGATCGCTGGAACACGTTCAGACAAGAGTCGCCTGGTCCAGTCGCCGGCTACCCTTGTTCTGAAATTAGTCCGCTAATGTAGTTGGTGGCGTTTCTCCTACCCGCACGACACATATTAGCAATTAGTCTACACCCCCAGATCCAAGTCAGGCCCTCCAGGTGGTGCAAACGGCGCCTGCACAGGGCCTGCATACGGCTGGAAGTGAGGAGTCCCAAAGCCTCCCCCGTTCCCGGAGGCATTTTGTATGGCAATGTGACGGCCCGTTAATACCGCGCACGGCGATGGTAAAAGAAGGTCTGGTTCAGGATATGTGCAATCGCGCATAGGTAGTAAGTCGATCGTATTGCTACCGCACAATAGCGTAAAGGCATGCATTAGGTCGGTCTTTAGTGTGACACAGGACGAGTAATCTTGATCTTTACAGTACTCGATGGCCTAACGAGATGAAGCCATTTAGTCGTACGTGGCTGTTAGCGGTCTCGACTTAAACAGCCCCAGCGTCCGATATTAAGAAGGTCACGGAAGCCTACCGGCTTTCAAGCACCATACAGTTTAAAGCGGGACTAAGTTATCCCACACTTGACTCTGCACATGTGTCCAGGTCTAATCCTCCTTAGTTGTCGCCCGCGCTTCTTATCAAGGAACACTGCAGAAGACTCGACTTCAAATTCTAGTTAAGCAGCCACCGCTAGGACTCGGCACTAATGCCGTAATATTTATAGCCCAAGCCTTGTGAGGTATATCGTACCAATAGATTGAGGAGTTGAATATGTTGTCAACCCATCCTCCGCACGCCAACGGTGACTAGATCTACATCTCGCACGGTTCAGCATGTTGGCTAGACGATCCGCTCACGCTTGGGTCTACTCCCTCGTTGTGACGTTCCACGCACTATTAGGCGACGATTCTGTATGGATCTGTACCTCTCCCCGATATCTTTTCGAGAGTTTTTGAACCCAGTCGGATCAATAGAGTGTCGACCTCTTTTCCGTGGACTCGGGTCCGGTTAACATATATGTAGCTGATAGCAAACTAAACTCGGAACTGCGACCCCGTTGATGCCGATACAGAAGCTACTCACCCGCGGCTGACCTTAGACGTCGCGGTCCCGCAACTTTGGAGCACAGCTATTGACTAGATCTGCGGAGACGCCAAAGCTGGCGATCTTCCTACAGCCTGTAATAGTGTCACCGTTGCGTGAGATGGTGCCAAAGGATAATATCTCAACGCCCATAGAGAGGTATCGGCCCATGGTCATGCGCCGGACATATGATAACCTCTATGTTTTAGGAAAATCCGGTTATTTAGACGATTGGCACAGTAGCTAACCTCAGATTACCCCTATGGCACTACCATGTACGAAACGGCAAGGACGCGCATTAGCATAATAGTAAAGTGGCAGTCATCCCACTGGTCCAGTGGGAGGCAATAGGAAACACAATCTGATCACCTAGGTGGCGCGAAACCTGCATTAATTTCAACGTCACCACCGTCCAGAGTCTTAAGATAAAGCGCTGAGGGTGGCTTCGAACGCTCACATCTAATTGACTCCGTTATATGTATGTCTGCTACCCATGCTCTGTGTATGGTAAGCGACTACATGCAGTTTTCGAATCTCTAGATCTCCTACGAGTACTGCCGACCTCCTATAATGGGCGGACATCCTTTAATGTACAGAAACTACGTTGTTCCGCCCCCGATAATGGATAGACGCAGTACAGTATAGTGGGCTCTGGGCACCCGAAAGGGTATGCGGCTGATATGAATCCGTGCGACCGTAATACTAAGCTTGCGGACTAATATTTCCCGAAGGAGATTAAACATAATTAGAAGTCAACGGTGTCGCGAGTTTGTGTGTGTTGGTTACGTTGTGCTGACTCTGCGACGTCTGTTTCGAATAACCTGAGGGAAAGCCTTGATAACCCAGAATTCGCAGGCTACGACAGGCCACTCGACACTCGGGAATTCAAGAGCTGGTGAGACCAGCTACTCACCTTCGTGGGGTATACGCCAAATAATTTAGTCGTCCTGACGGACCCCAATGGCCCTGCATCGCGCGTAGTTAGACGGAACTCTGAACGGGCGTGACCAAGGGGGGCACGTGCATCATTATCGTAAGAATTGTTGCATGTTCATACTATTCGCCTATTTGATTACGGGACACGGGAGTGATCCTCGATGCTAAACCACATATTTCGTTCCTATACTAGGCACCCAACGGCCATCGCAAATTGCGCCTACACTTATAGTTCAGGCGCGATTAGAATAACTTAAGGCTAGGGATCTTGCCTAGTGGCTTCACGAAACCGGCCTTCGTTAGGTGACGCAAACTTCGGCGTGTCGATAGAGATCACTATTTGACGCATTTATATGAGTGCATCCATGAGGCTAGACTCACGTACAGGTCGTACCACTTATAAATGGAATGAACATTACGGCGTCATAGCGTTTAGTTAGACTTTGCTTCGCAAGGGAATCACTACAGCATTATTCGTTAATTACATGACAGCGGGACGCGTCGTGGGGTTCAAAAAGCCGTTCTTTGAGGCGATCGCGTGTACCAGCGGTGAGGAAGAACGGGTATGGCACTACTTGCTCACCGGGTGAAGTACAATAGATGTGTTGCGAGACATTCAGCATTGACCTTGGTCAGCTTGTGGCTGTTTATTGTCCCCTTGTCATGGCCGCTCTATTGTGAGCCGAGGAGGCAGTTTCCTTTGGAGAGTACGAACGTAACCCATAGACGCAACGCTTAGCACCACTTGTGCATGCGCGGTAAGGGGTTCGATTTCATCGAGCAGGCTCCAACGGGGCTGTTTTCTCGTTGTTCGACATGCTCTGGCCTATGGCCTATTAAATGTGGGCGTTGGATCCCGCGCCCAAGAGTGCGCTTCCATATGGGCGGAAGCCCTCCCCAACCGGAGGTAGGGCAGGGAGACTGCACTAAGCTATTAACTGGAGCTAGACCGAAGTATAATTCCCTTAGTTTCACGGCGCCCGCGGCACCATGAGGGCATCTGGGCGCTTACAGGCGTTGTCCTCAGGCGATTCATCCTGGACGAGCTTTATTTGAGATAGTGAACAAAAGTGCCCCACAACGCCAGCTCTGGGGCCCTGTCAGCCCGTAGATGGTGACGAGTGGAGCAGAACCCTTTGCGCTTCGCTCACAAGATAAATACCCACAGTGAAATGCGAGCTTTTAATGGAGCTGCTGACTAGCGTTCTCCACGCCAACCCGTAGGTTATGTTGGACTGATTGCCTCAGCGAATCGACGCCACAGCCCCGAGGGGAGTTACCTACAGCATATCCTAAGGCAATTACATAAGCCGTATGTTACGCTTAGGTCCCGTATACAGTACCCGATAGAAGTACGTCGAGTGCGATAGGACATCCTTTCTGGGAGTAGGTAGGGGCTACAGCTGACCACGGCTCTCCTGAGAGCATGGCGGCTGAGGTAATTTTGTTACTGATTTTGCATGCAATAACCAAGTCCATCTACTGAGCGAAGACTGAATAGGCGGTGTGGCTCAGGCTTACTTGGTCAGCTTTTGAGTACCACAGTCATACGGGTAGCAGATTTGCTGGAGAACTGGATAGTTCTCCCCTCTAGGGGACTACAGCGCCATCATAGACATGTAGTACTCTTGTCCTGTTCCAAGACATGTGGGGCTCCGGGCGCTCTGTACCGGGAAAATACCATTATGGTCTCAATCATCGCAGGGCATCATACGTAACCGTCGGAAGTTAAGGCCCCGAGCCAATGCCGGTCAATCGACTACACAAACTTAAATTGGTGGGTTTCAATATATGTGGTGAAAATAAGTTCGAAGAGGCATTGGGCACCTAAAACCTCTGACATATCGAACACATGCTTACCTCACAGACTAAATCTTACGCGGCTACGTCTGTCACACGCTCATTGTTAGATCGGTTGCCAGCGCGAACCCACATCCAGACGCTGAGCCTGAGAGAGACATCCGGGGCGTTACGCTATGGGCGATGAGCGTCAGTCCCTTTATTAGCGATTATCGGCTCCAAATGTCACTCGAAGAATCGGCATTGTCGTTTTTCCCGCCTGTAGCTCTTGTTCGCAGGGTATTACAAAACTACGGGACGCTTGAGACGTGTGATCCGGGAAGGTCCAAAACCTGGCATAGCGCCGGGTTGGTCCCGTTGTGGGAGTCGTATAGTGGTTATGTCGTACGAATGCAAGTTTCAATGCTATCTTGCATTTCCGAATGGTCCTCAATTTCACTCAAGTGGATCAAGAGGTGTTTCTCGGGTAGTGGTTATGCTGCGACTTTAGAAACTAGTCGCCTAGCCTCGGCCGCTGGCGGGGGAACAGGGAGGTCCGTGTAATTCCGGTTAGTTAAGTCGTTGGAGGCTTATATTTGTCGGTCAGTTTCATCAGCTAGCGCTTCAATTGGTCGTTACGACGTTCTGTGCCATAAAGTATCAAATATACATTGGTTCGCATTCGCACATCTAAACAGACAGCGGGTTCGTTCTAACGTAATCCGCCTCCCCGATATTCATACAAAGAGTTTCTTATGACAACAACCGAGACTTTACCATGCGCTATTCTACGCAGATGGTTTAAGCATATTGCGGGGCTTGCGAAGGTCAGATCGATGGATCTAATCCAGGCGTATGGGTGGACCCTTGTGCCAGGACACTCGCATTCGAGGGATTCCGGCCATCATGAGGTTAATCTAGACAGGCTGCGATTGGACGGAGGTCGTAGCTCCTCAAATGCCGAAACACGTTGTTTGTCACGTATTGGATGCGTGGTTGCCAAGAACTCTCGCAACAAGTATCCGGGCGGGGTGCCAGTGAACAAGGCACTCTCTTGAACGGCACTTTCATAACGGGCACGAAAGAACTGCTGTGGACCTCGGGACCATAAATGTTGCAACGCGTCCAGTTGCACGCTTCAAGCCCCGAGCCACAAGTCGGAAAGGCTAATTCGAGCTTTGCAAGTTTATGGAAACCCCGCTGTATATCCTAACAACCATCATGGCAATACTATGAAGATACGGACACCAGGGCGCCAGCAGCCTTTCATGTCTTCTCAGGCCTTCCGGCTCAAGCACAGTAGCAGCTCTGCATGTGGCACACGGGGCAGCTGACCATCCCCTCTCCTACTCTATGACGGGGAGAATAGAAACAGGCGTTAGGGATGCGACGGGTCTGTGTTGATCAATGACACGTCGTCGGAAAAAGGGGCTCTTGCAGCATTTTACAAACTAATGGAAGGACACACGAACAATTGACTTATCTAGCTTCCGGGATCGCCTTGCATGTGAGCGGTATCTCTGTACTGTGCACCGCCACGGTACGTGCGTACGCACTGTAGACGTGTTTGGAAGGCTCCGGATCATGGAAGGGCTCTCTGATACGCTCCGATCGTCCATTGCCGCGGTCCGGCGCTCCGACTAGGAGGAGATACGGCACCTGGGGATGGTTCTGTTCCCCCACTTTCTAATTAATAATCGGATGACCGTTTCCTTTAAGTCGCTCTCGTGGTCGGAACTTACATCGGATCGTATGTACACTTCATTGCGTGTGTTCGCCATCGCAAAGACAAGGATCTATATGAAAAGACTTACAGCACGATACGCTTACCCCAATCAAGTGATGATGGCATTCAAGTGATAGATCACAATATTCTTCGTCACCAAGGACAGATAGCAGCGGGCTAACGATTTCCGAATCGGGGATAGTCCAGTTCAAGATTAGACCGTAACGTATGAAGCGCTCGCTACCGTTCACGCGCACCTCGCCGTCGCCAAGCACAAAGATTCACCAATGTGTAGCAAGCGCTATCGTCAAAGGTAGATAGTAAAAATAGGTATTTTTTGCCAAAACTTAACCTTAGGGTTGAGGGCGGAGATGTCCATTAAAGAAATCATTCTATGCCACTAATAGCTCAGTGGAGAATCGTATAGGGTGGAATGGACATCGTGACGCTGTGGTACTGCTGTACTCCTACCAAAGTAAGAACGCAATCATTGTCCAGCCTTGCTCGCAAAGTTTGGATTTACCAGCGTCGTGCCTCATATGCACTTTGCGGAACAAAGGTTCCGTAAATTTTACATGCATGACAACAGGTCCATCAAGCTACGAGTATAAGCTAGACGCCCCTTACCTACCACCGCCAAAGAGGTCCTGGTCATTATCCCCGCATTGGAAGAGCCTATCGGCGCTTTTCGTTGAGTTTCAGTCCATTGGCCGAAAATGCTTTGTTTCTGAAGTCCGTGAGTAAGTTATTACACTTGTTGTCTCGCCCAAACTCAAGGGAGTGACGCCGTACGTTAAAATCGTTGCCTTTGGAGCTCGAAACGAGTGCGTGCCGAGATTCCCCACGTCGTTCTTCATGTCCATGACTAACTCATTCTGTTGTCTGTATGTCACAACAATTCGGTATTTGGGCCACACACCTCATTCGGAAATACAGCATACCCGCATAGCGGTATCTCTTGGATTCATTAATCGTAGTTAACTCACTATAACGCGCGCCGGGCGCGATGAATTGACAACGGTCTACCTCTAACCGGGGACGAGCCCGCGGTGCAAGCGACAAGTTGGAGACTCTGGTAGTTGCTTAATCTAATGGTTGAAGGGTTATGACATTCATTCTCTCCAATGTCCAAGCGGCTTATCAATGCGCACATCGCCGACTCACATGGCCGGGACTGGATCATCAAACGTCGTATGGACAGAGTATAGCTTCGCGACAGATCATGTCGGCCTATTATCGCACAGCGGCGTTCGGAGGCTGTTCGACACAGACGGGGCCACTAGTAGACGTGATATCCAGCTCAATGTCCAGCGCCCGACCGGGAGCACGGAATAGTGGAATATTCCTAAGACTGTGGCCTAATCACCCCTTTAAACAGTCTACTGGTGAGATCCTGTTATTATTCTTATGTGAGTCTGGAGGAGCTTCCGGCGATGACAGGGTGGAGGCTTATTCGAGAGGACACGTCCTGAAGGAGCATTAGTTACGGCAATCGGATCGGCTCATCAATACTAGCATGCGCACGAGCATGCCAAGAAACTCTACACAGTCAGCGCATTGGCGGGCGAACTTTTACATTGGAATGGCGTGTCTAGATTTCATGGAGCATATTACATGTAATAACAACAATCACATAATAACGGATCGCACAGGTGCGGCGACCCGACGGATCTGAACAGCGCTTTGAGACCTAGTTCTATCTACGGGGCAGGATGGCTAGGAAAAACTCAGGATTCTAAGGGTTGCTTCCTCTTGGAACCACCGAGGTCGGTTTGCAGTTCGACGGCCAGATGTTTCTGCTTACGAATAGTAACTGTATTCTCAAAGGAATTATTACACTATAGATTCCAGATACAGACTCTAGTATTAAGGCAACAATAGTCCAGATTGATTCCGCAATACAGAGTGGTTAAGTTCATCCTGCATGTTAGTAGCGGGGTCGGCAAATGTATTGTGATCGATGATGGACAGAACGAATGGGGAGCTGCGTTTCGTCGATAGGTCCCATGACAGGAGGTAGTTGTACTATGCTTAAGAGAGTTAATTGTCTTACACTACCACCGACCAGTGCCCCACCGTGCACTGGTTGCGCGAGCACAAGCCATTCCAGGACAACAGTGTGGACCTGTAGAAGTTACCTGCCGCCCACCTTCCCTCCATAACGTTAGAAAAGGATGGGGCTCTTACTGCCGACCCGAGCCCATGGAGGCTCTGGGTTTATGCTAACTGCGCTGTGACAAGATTGTATCCTGTTACAAAGCAGAGGCCGGTGGTCTTTTGTTGTGTAACTTATAATGACCCGAGGACACACACTTAAACTGTAGTCTTAGTTTAGAACAAATCGGGAACTCTCCTCCTAATTCCCTTGATTGTCGTCGCGTTCTAGCCTCGCCCATGACAGAATCTATAGACAACTCTGATACATACAAATGGTGTTAATGGAGTTCCGGGCA";
    //char *s = "AATCCGTTCGGA";
    //char *t = "TTCGGATACGTACG";
    //define a penalty matrix
    //if match +1
    //mismatch(substitution) -2
    //linear gap -2
    //alignment initiation

    int m = strlen(s)+1;
    int n = strlen(t)+1;

    int **A = new int *[m];
    for (int i=0;i<m;i++)
        {A[i] = new int[n];}

    for(int i=0;i<m;i++){A[i][0]=0;}
    for(int j=1;j<n;j++){A[0][j]=0;}

    int max_score = 0;
    int row_idx = 0;
    int col_idx = 0;
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            int match = 0;
            if(s[i-1]==t[j-1])
                match=1;
            else match = -2;
            int gap = -2;
            A[i][j] = max(max(A[i-1][j-1]+match,0),max(A[i-1][j]+gap,A[i][j-1]+gap));
            if(A[i][j]>max_score)
            {
                max_score = A[i][j];
                row_idx = i;
                col_idx = j;
            }
        }
    }

    /*for(int i=6160;i<6170;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }*/

    cout << endl;
    cout << max_score << endl;
    //cout << row_idx << ' ' << col_idx << endl;
    //cout << s[row_idx-1] << ' ' << t[col_idx-1] << endl;

    stack<char> s_stack;
    stack<char> t_stack;
    m = row_idx;
    n = col_idx;
    while(A[m][n]||A[m+1][n]||A[m][n+1])
    {
        if(A[m][n]==A[m-1][n]-2)
        {
            s_stack.push(s[m-1]);
            t_stack.push('-');
            m--;
        }
        else if(A[m][n]==A[m][n-1]-2)
        {
            t_stack.push(t[n-1]);
            s_stack.push('-');
            n--;
        }
        else
        {
            t_stack.push(t[n-1]);
            s_stack.push(s[m-1]);
            m--; n--;
        }

        //cout << s_stack.top();
    }

    //cout << s_stack.size() << ' ' << t_stack.size();

    while(!s_stack.empty()){cout << s_stack.top(); s_stack.pop();}
    cout << endl; cout << endl;
    while(!t_stack.empty()){cout << t_stack.top(); t_stack.pop();}

    return 0;
}