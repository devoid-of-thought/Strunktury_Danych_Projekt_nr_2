#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "Prioqueue.h"
#include "kopiec.h"
using namespace std;
using namespace chrono;

template <typename QueueType>
void runTest(const string& queueName, ofstream& insertFile, ofstream& extractFile, ofstream& findFile, ofstream& modifyFile, ofstream& sizeFile, ofstream& allFile, int size, const vector<vector<pair<int, int>>>& datasets) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(INT32_MIN, INT32_MAX);

    long long totalInsert = 0, totalExtract = 0, totalFind = 0, totalModify = 0, totalSize = 0;

    for (int f = 0; f < datasets.size(); ++f) {
        QueueType pq1;
        QueueType pq2;
        QueueType pq3;
        QueueType pq4;
        const vector<pair<int, int>>& data = datasets[f];
        for (const auto& elem : data) {
            pq1.insert(elem.first, elem.second);
            pq2.insert(elem.first, elem.second);
            pq3.insert(elem.first, elem.second);
            pq4.insert(elem.first, elem.second);
        }


        auto startInsert = high_resolution_clock::now();
        pq1.insert(dist(gen), dist(gen));
        auto endInsert = high_resolution_clock::now();
        totalInsert += duration_cast<nanoseconds>(endInsert - startInsert).count();
        cout << "insert wykonany dla : " << queueName << " " << to_string(size) << " elementów "<< " dla "<< to_string(f) <<" próby "<< endl;

        auto startExtract = high_resolution_clock::now();
        pq2.extractMax();
        auto endExtract = high_resolution_clock::now();
        totalExtract += duration_cast<nanoseconds>(endExtract - startExtract).count();
        cout << "extractmax wykonany dla : " << queueName << " " << to_string(size) << " elementów "<< " dla "<< to_string(f) <<" próby "<< endl;


        auto startSize = high_resolution_clock::now();
        pq4.returnSize();
        auto endSize = high_resolution_clock::now();
        totalSize += duration_cast<nanoseconds>(endSize - startSize).count();
        cout << "returnsize wykonany dla : " << queueName<<" rozmiar = " << pq4.returnSize() << " " << to_string(size) << " elementów "<< " dla "<< to_string(f) <<" próby "<< endl;

        auto startModify = high_resolution_clock::now();
        pq3.modifyKey(rand() % size-1 , dist(gen));
        auto endModify = high_resolution_clock::now();
        totalModify += duration_cast<nanoseconds>(endModify - startModify).count();
        cout << "modify wykonany dla : " << queueName << " " << to_string(size) << " elementów "<< " dla "<< to_string(f) <<" próby "<< endl;

        auto startFind = high_resolution_clock::now();
        pq4.findMax();
        auto endFind = high_resolution_clock::now();
        totalFind += duration_cast<nanoseconds>(endFind - startFind).count();
        cout << "find-max wykonany dla : " << queueName << " " << to_string(size) << " elementów "<< " dla "<< to_string(f) <<" próby "<< endl;
    }

    int powtórzenia = datasets.size();
    insertFile << queueName << "," << size << "," << totalInsert / powtórzenia << "\n";
    extractFile << queueName << "," << size << "," << totalExtract / powtórzenia << "\n";
    findFile << queueName << "," << size << "," << totalFind / powtórzenia << "\n";
    modifyFile << queueName << "," << size << "," << totalModify / powtórzenia << "\n";
    sizeFile << queueName << "," << size << "," << totalSize / powtórzenia << "\n";

    allFile << "insert," << queueName << "," << size << "," << totalInsert / powtórzenia << "\n";
    allFile << "extract," << queueName << "," << size << "," << totalExtract / powtórzenia << "\n";
    allFile << "returnSize," << queueName << "," << size << "," << totalSize / powtórzenia << "\n";
    allFile << "modifyKey," << queueName << "," << size << "," << totalModify / powtórzenia << "\n";
    allFile << "findMax," << queueName << "," << size << "," << totalFind / powtórzenia << "\n";
}

vector<pair<int, int>> generujTablice(int size) {
    vector<pair<int, int>> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(INT32_MIN, INT32_MAX);
    for (int i = 0; i < size; ++i) {
        int priority = dist(gen);
        int value = dist(gen);
        data.emplace_back(value, priority);
    }
    sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    return data;
}

int testowanie() {
    srand(time(0));
    vector<int> testSizes = { 5000,8000, 10000, 20000,35000, 50000,80000, 100000, 175000, 250000};
    string path =  "/home/userbrigh/CLionProjects/Strunktury_Danych_Projekt_nr_2/";

    ofstream insertFile(path + "insert.csv");
    ofstream extractFile(path+"extract.csv");
    ofstream findFile(path+"findMax.csv");
    ofstream modifyFile(path+"modifyKey.csv");
    ofstream sizeFile(path+"returnSize.csv");
    ofstream allFile(path+"wyniki.csv");

    insertFile << "kolejka,liczba_elementow,czas_ns\n";
    extractFile << "kolejka,liczba_elementow,czas_ns\n";
    findFile << "kolejka,liczba_elementow,czas_ns\n";
    modifyFile << "kolejka,liczba_elementow,czas_ns\n";
    sizeFile << "kolejka,liczba_elementow,czas_ns\n";
    allFile << "operacja,kolejka,liczba_elementow,czas_ns\n";

    for (int size : testSizes) {
        vector<vector<pair<int, int>>> tablice;
        for (int i = 0; i < 50; ++i) {
            tablice.push_back(generujTablice(size));
        }
        runTest<Kopiec>("Kopiec", insertFile, extractFile, findFile, modifyFile, sizeFile, allFile, size, tablice);
        runTest<Kolejka>("Lista wiązana", insertFile, extractFile, findFile, modifyFile, sizeFile, allFile, size, tablice);
    }

    insertFile.close();
    extractFile.close();
    findFile.close();
    modifyFile.close();
    sizeFile.close();
    allFile.close();

    cout << "Testy zakończone, wyniki zapisane w plikach.\n";
    return 0;
}
