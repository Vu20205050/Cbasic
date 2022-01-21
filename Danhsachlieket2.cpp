
#include <iostream>
#include <list>

int main ()
{

  std::list<int> mylist (3,100);       
   std::cout << "danh sach ban dau:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it; 
	 std::cout << '\n'; 
	 // list::push_front          
  mylist.push_front(300);

  std::cout << "danh sach sau lenh push_pront:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
  // list::push_back
  mylist.push_back (200);

  std::cout << "danh sach sau lenh push_back:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';
//list::pop_back
mylist.pop_back ();
  std::cout << "danh sach sau lenh pop_back:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';
//list::pop_front
mylist.pop_front ();
std::cout << "danh sach sau lenh pop_front:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';
//size
  std::list<int> mylist1;
  mylist1.push_back (100);
  mylist1.push_back (200);
  mylist1.push_back (300);
  std::cout << "Popping out the elements in mylist1:";
  while (!mylist1.empty())
  {
    std::cout << ' ' << mylist1.front();
    mylist1.pop_front();
  }
  std::cout << "\nFinal size of mylist1 is " << mylist1.size() << '\n';
  //list clear()
  std::list<int> mylist2;
  std::list<int>::iterator it;

  mylist2.push_back (100);
  mylist2.push_back (200);
  mylist2.push_back (300);

  std::cout << "mylist2 contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist2.clear();
  mylist2.push_back (1101);
  mylist2.push_back (2202);

  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  //list earase()
  std::list<int> mylist3;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist3.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist3.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist3.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist3.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist3.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist3.begin(); it1!=mylist3.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';
  return 0;
}
