#include <iostream>
#include <set>
#include <stack>
#include <random>
#include <chrono>
#include "src/ComplexNum.h"

using namespace std;

int main(){
	//int
	multiset<int> A;
	int a = 10000;
	cout << "Multiset" << endl;
	// multiset 1000---------------------------------------------------------------
	cout << "1000 elements (int)" << endl;
	cout << "insert ";
	auto start = chrono::steady_clock::now();
	for(int i = 0; i != 1000; i++) {
		A.insert(rand());
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> duration = end - start;
	cout << duration.count() << endl;

	cout << "search ";
	A.insert(a);
	start = chrono::steady_clock::now();
	A.equal_range(a);
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	A.clear();
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;
		
	// multiset 5000---------------------------------------------------------
	cout << "5000 elements (int)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 5000; i++) {
		A.insert(rand());
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "search ";
	A.insert(a);
	start = chrono::steady_clock::now();
	A.equal_range(a);
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	A.clear();
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // multiset 10000----------------------------------------------------
    cout << "10000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 10000; i++) {
        A.insert(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    A.insert(a);
    start = chrono::steady_clock::now();
    A.equal_range(a);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    A.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 15000---------------------------------------------------------
    cout << "15000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 15000; i++) {
        A.insert(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    A.insert(a);
    start = chrono::steady_clock::now();
    A.equal_range(a);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    A.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 20000-----------------------------------------------
	cout << "20000 elements (int)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 20000; i++) {
		A.insert(rand());
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "search ";
	A.insert(a);
	start = chrono::steady_clock::now();
	A.equal_range(a);
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	A.clear();
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // multiset 30000---------------------------------------------------------
    cout << "30000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 30000; i++) {
        A.insert(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    A.insert(a);
    start = chrono::steady_clock::now();
    A.equal_range(a);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    A.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 40000---------------------------------------------------------
    cout << "40000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 40000; i++) {
        A.insert(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    A.insert(a);
    start = chrono::steady_clock::now();
    A.equal_range(a);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    A.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 50000---------------------------------------------------------
    cout << "50000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 50000; i++) {
        A.insert(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    A.insert(a);
    start = chrono::steady_clock::now();
    A.equal_range(a);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    A.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;


    //=====================================================================================
    //=====================================================================================

	// ComplexNum
	multiset <ComplexNum> B;
	ComplexNum b(10000, 10000);

	// multiset 1000-------------------------------------------------------------------
	cout << "1000 elements (Imag)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 1000; i++) {
		ComplexNum j(rand(), rand());
		B.insert(j);
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "search ";
	B.insert(b);
	start = chrono::steady_clock::now();
	B.equal_range(b);
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	B.clear();
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // multiset 5000-------------------------------------------------------------------
    cout << "5000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 5000; i++) {
        ComplexNum j(rand(), rand());
        B.insert(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    B.insert(b);
    start = chrono::steady_clock::now();
    B.equal_range(b);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    B.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 10000-------------------------------------------------------------------
    cout << "10000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 10000; i++) {
        ComplexNum j(rand(), rand());
        B.insert(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    B.insert(b);
    start = chrono::steady_clock::now();
    B.equal_range(b);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    B.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 15000------------------------------------------------------------------------------
	cout << "15000 elements (Imag)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 15000; i++) {
		ComplexNum j(rand(), rand());
		B.insert(j);
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "search ";
	B.insert(b);
	start = chrono::steady_clock::now();
	B.equal_range(b);
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	B.clear();
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // multiset 20000-------------------------------------------------------------------
    cout << "20000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 20000; i++) {
        ComplexNum j(rand(), rand());
        B.insert(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    B.insert(b);
    start = chrono::steady_clock::now();
    B.equal_range(b);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    B.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 30000-------------------------------------------------------------------
    cout << "30000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 30000; i++) {
        ComplexNum j(rand(), rand());
        B.insert(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    B.insert(b);
    start = chrono::steady_clock::now();
    B.equal_range(b);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    B.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 40000-------------------------------------------------------------------
    cout << "40000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 40000; i++) {
        ComplexNum j(rand(), rand());
        B.insert(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "search ";
    B.insert(b);
    start = chrono::steady_clock::now();
    B.equal_range(b);
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    B.clear();
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 50000----------------------------------------------------------
	cout << "50000 elements (Imag)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 50000; i++) {
		ComplexNum j(rand(), rand());
		B.insert(j);
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "search ";
	B.insert(b);
	start = chrono::steady_clock::now();
	B.equal_range(b);
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	B.clear();
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;


//======================================================================================
//======================================================================================


	//stack
	//int
	stack<int> C;
	cout << "Stack" << endl;
	// stack 1000-----------------------------------------------------------------------
	cout << "1000 elements (int)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 1000; i++) {
		C.push(rand());
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 1000; i++) {
		C.pop();
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // stack 5000-----------------------------------------------------------------------
    cout << "5000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 5000; i++) {
        C.push(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 5000; i++) {
        C.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 10000------------------------------------------------------------------
	cout << "10000 elements (int)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 10000; i++) {
		C.push(rand());
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 10000; i++) {
		C.pop();
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // multiset 20000------------------------------------------------------------------
    cout << "20000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 20000; i++) {
        C.push(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 20000; i++) {
        C.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 30000------------------------------------------------------------------
    cout << "30000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 30000; i++) {
        C.push(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 30000; i++) {
        C.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 40000------------------------------------------------------------------
    cout << "40000 elements (int)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 40000; i++) {
        C.push(rand());
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 40000; i++) {
        C.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 50000-------------------------------------------------------------
	cout << "50000 elements (int)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 50000; i++) {
		C.push(rand());
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 50000; i++) {
		C.pop();
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;


//===================================================================================
//===================================================================================


	stack<ComplexNum> D;
	// stack 1000-------------------------------------------------------------------------
	cout << "1000 elements (Imag)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 1000; i++) {
		ComplexNum j(rand(), rand());
		D.push(j);
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 1000; i++) {
		D.pop();
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // stack 5000-------------------------------------------------------------------------
    cout << "5000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 5000; i++) {
        ComplexNum j(rand(), rand());
        D.push(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 5000; i++) {
        D.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 10000-----------------------------------------------------------------------
	cout << "10000 elements (Imag)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 10000; i++) {
		ComplexNum j(rand(), rand());
		D.push(j);
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 10000; i++) {
		D.pop();
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;

    // multiset 20000-----------------------------------------------------------------------
    cout << "20000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 20000; i++) {
        ComplexNum j(rand(), rand());
        D.push(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 20000; i++) {
        D.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 30000-----------------------------------------------------------------------
    cout << "30000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 30000; i++) {
        ComplexNum j(rand(), rand());
        D.push(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 30000; i++) {
        D.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

    // multiset 40000-----------------------------------------------------------------------
    cout << "40000 elements (Imag)" << endl;
    cout << "insert ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 40000; i++) {
        ComplexNum j(rand(), rand());
        D.push(j);
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl;

    cout << "remove ";
    start = chrono::steady_clock::now();
    for (int i = 0; i != 40000; i++) {
        D.pop();
    }
    end = chrono::steady_clock::now();
    duration = end - start;
    cout << duration.count() << endl << endl;

	// multiset 50000----------------------------------------------------------------------
	cout << "50000 elements (Imag)" << endl;
	cout << "insert ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 50000; i++) {
		ComplexNum j(rand(), rand());
		D.push(j);
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl;

	cout << "remove ";
	start = chrono::steady_clock::now();
	for (int i = 0; i != 50000; i++) {
		D.pop();
	}
	end = chrono::steady_clock::now();
	duration = end - start;
	cout << duration.count() << endl << endl;
}