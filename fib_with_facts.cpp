#include <iostream>
#include <vector>

// creates a vector populated with factors of x found in v
std::vector<int> factors(const int x, const std::vector<int> v){
  std::vector<int> facts;
  for (int i = 0; i < v.size(); ++i){
    if (v[i] != 0 && v[i] != 1 && v[i] != 2 && v[i] != -1 && v[i] != -2 
        && v[i] != x && x % v[i] == 0){ //messy garbage to exclude trivial factors
      facts.push_back(v[i]);
    }
  }

  return facts;
}

// a function that takes 2 ints, a vector to populate, and a limit as its arguments
void fibonacci(int& x, int& y, std::vector<int>& v, int n){
  int t = 0;
  v.push_back(x); // populate v with our intial values
  v.push_back(y);

  if (n > x + y && x + y > 0)
    while (x + y <= n){
      t = x + y;
      x = y;
      y = t;
      v.push_back(t);
    }
  else if (n < x + y && x + y < 0)
    while (x + y >= n){
      t = x + y;
      x = y;
      y = t;
      v.push_back(t);
    }
  else std::cout << "Bad input pal\n";
}


int main(){
  while (true){
    // declare our variables
    std::vector<int> vfibonacci;
    int a = 0;
    int b = 0;
    int n = 0;

    std::cout << "Gimme two ints and a stop pal" << std::endl;
    std::cin >> a >> b >> n;
    fibonacci(a, b, vfibonacci, n);
    //include factors?
    char choice;
    std::cout << "Include factors? ";
    std::cin >> choice;
    switch (choice){
      case 'y':
      // cycle through all the elements in vfibonacci except the last
      for (int i = 0; i < (vfibonacci.size() - 1); ++i){
        std::cout << vfibonacci[i] << ", ";
        // build a sub vector of all elements of vfibonacci up to vfibonacci[i]
        std::vector<int> subvfib;
        for (int j = 0; j <= i; ++j)
          subvfib.push_back(vfibonacci[j]);
        // build a vector of factors of vfibonacci[i] found in subvfib, and output them
        std::vector<int> facts = factors(vfibonacci[i], subvfib);
        if (facts.size() > 0){
          std::cout << "factors of " << vfibonacci[i] << ": (";
          for (int k = 0; k < facts.size(); ++k)
            std::cout << facts[k] << " ";
          std::cout << ")";
        }
      }
      break;
      case 'n':
      for (int i =0; i < (vfibonacci.size() -1); ++i)
        std::cout << vfibonacci[i] << ", ";
      break;
      default:
      std::cout << "bad input";
      break;
    }
    // print out the last element, with (slightly) different formatting
    std::cout << vfibonacci.back() << ".";
    std::cout << std::endl;
  }
  return 0;
}
  
