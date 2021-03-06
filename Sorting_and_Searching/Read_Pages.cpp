#include <iostream>
using namespace std;

#define ll long long int

bool isValidConfig(ll books[],ll n,ll k,ll ans)
{ //mid is the curretn ans.
    int students=1;
    ll current_pages = 0;
    for(int i=0;i<n;i++)
    {
        if(current_pages+books[i] > ans)
        {
            // if the no. of pages exceed the value of cur_ans(mid)
            // then, we will take up one more student.
            // and the no of pages read by that new student, will be
            // initialised to books[i]
            current_pages = books[i];
            students++;
            if(students > k)
            {
                return false;
            }
        }
        else{ // the <= condition
            current_pages += books[i];
            // we will increment the no. of pages, 
            // as this book can be read by the student.
        }
    }
    return true;
}

ll binarySearchbooks(ll books[],ll n,ll k)
{
    ll total_pages = 0;
    ll s,e;
    s=0;
    for(int i=0;i<n;i++)
    {
        // here, there is a sort of virtual array, on which we are 
        // implementing binary search to get the max no. of pages.
        total_pages += books[i];
        s = max(s,books[i]); //here, s is being assigned the maximum no. of pages in a book
        // as, the final ans will have atleast that value.(as, that book will be assigned to some student)
    }

    e = total_pages;
    int final_ans = s;

    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(isValidConfig(books,n,k,mid))
        {
            // true
            // search in the left part
            final_ans = mid;
            e = mid - 1;
        }
        else
        {
            // false
            // search in the right part
            s = mid + 1;
        }
    }

    return final_ans;
}
int main() {

    ll n,k; // n = no. of students , k= no. of books
    cin >> n >> k;
    ll books[10005]; // array contains info about the no. of pages in each book.
    for(int i=0;i<n;i++)
    {
        cin >> books[i];
    }
    cout << binarySearchbooks(books,n,k) << endl;

    return 0;
}
