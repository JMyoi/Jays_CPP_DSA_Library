#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <iomanip>
#include "dictio.hpp"

template <class E, class K>
class HashTable {
public:
  HashTable(int divisor = 11) {D=divisor; ht=new SortedChain<E,K>[D];}
  ~HashTable(){delete [] ht;}
  HashTable<E,K>& Delete(const K& k, E& e) {ht[k % D].Delete(k,e); return *this;}
  int Insert(const K& k, const E& e) {return ht[k % D].Insert(k, e);}
private:
  int D;
  SortedChain<E,K> *ht;
};

class TypeE {
public:
  long key;
  long value;
  TypeE(){}
  long Key(){return key;}
  long Value(){return value;}
};

void runMonteCarlo(int n, int D) {
  const int TRIALS = 1000;
  long long totalComparisons = 0;

  // Pool of 10000 unique integers (1..10000); shuffle each trial for unique random samples
  std::vector<int> pool(10000);
  std::iota(pool.begin(), pool.end(), 1);
  std::mt19937 rng(std::random_device{}());

  for (int step = 0; step < TRIALS; step++) {
    std::shuffle(pool.begin(), pool.end(), rng);

    HashTable<TypeE, long> HT(D);
    long long trialComparisons = 0;
    TypeE e;

    for (int i = 0; i < n; i++) {
      e.key   = pool[i];
      e.value = pool[i] * 10;
      trialComparisons += HT.Insert(e.key, e);
    }
    totalComparisons += trialComparisons;
  }

  double mcAverage   = (double)totalComparisons / TRIALS;
  double calcAverage = (double)n * (n - 1) / (4.0 * D);  // n(n-1)/(4D)

  std::cout << std::left
            << std::setw(16) << n
            << std::setw(24) << calcAverage
            << mcAverage << "\n";
}

int main() {
  const int D = 50;
  std::cout << std::left
            << std::setw(16) << "Input Size (n)"
            << std::setw(24) << "Calculated [n(n-1)/4D]"
            << "Monte Carlo Average\n";
  std::cout << std::string(60, '-') << "\n";

  runMonteCarlo(100,  D);
  runMonteCarlo(500,  D);
  runMonteCarlo(1000, D);

  return 0;
}
