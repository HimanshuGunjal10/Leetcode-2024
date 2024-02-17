#include <iostream>
#include <vector>
using namespace std;

#if 0
void print_vec(vector<int>& vec)
{
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
#endif

int minEatingSpeed(vector<int>& piles, int h)
{
    sort(piles.begin(), piles.end());
    int l = 0;
    int maxPile = piles[piles.size()-1];
    int r = maxPile;
    int mid = 0;
    int count = 0;
    int currentPile = 0;
    int result = maxPile;

    while(l<=r)
    {
        count = 0;
        mid = l + (r-l)/2;

        for(int i=0; i<piles.size(); i++)
        {
            currentPile = piles[i];
            count += currentPile/mid;
            if(currentPile%mid > 0)
                count++;
        }
        if(count <= h)
        {
            r = mid-1;
            result = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    return result;
}


int minEatingSpeed_1(vector<int>& piles, int h)
{
    sort(piles.begin(), piles.end());
    // print_vec(piles);
    int largest_pile = *(piles.rbegin());
     
    //binary search
    int l=0, r=largest_pile;
    int mid = 0;
    int res = largest_pile; //!need this to properly store the res

        while(l<=r)
        {
            mid = (l+r)/2;
            int i = 0;
            int total_hours_eating = 0;
            while(i<piles.size() && mid > 0) //! mid>0 is important
            {
                total_hours_eating += (piles[i]/mid);
                if(piles[i]%mid > 0)
                    total_hours_eating++;
                i++;
            }
            if(total_hours_eating <= h)
            {
                r = mid-1;
                if(mid) //check mid!=0 before updating
                    res = min(res,mid);
            }
            else if(total_hours_eating > h)
                l = mid+1;
    
        }
    return res;
}


int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(11);
    // vec.push_back(20);
    // print_vec(vec);
    
    cout << "Koko's min speed should be: " << minEatingSpeed(vec, 18);

    cout << endl << "La Fin!" << endl;
    return 0;
}