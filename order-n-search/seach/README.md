# search
  > method to search information in big volumes of data
  - applied in ordered or disordered files
  - 
  
## linear search
> linear scan, element by element in a data set

> in a disordered set, only linear search is used?
    
- yes, so first you order the set, then you search  

<br />

## binary search
> divide and conquer
- only used in ordered sets
- starts in the middle of the set and test if the element is equal, lower or higher
  
    1. it is equal? returns the address
    2. it is lower? divide the set by two and search in the left set, starting by the middle value of it
    3. it is higher? divide the set by two and search in the right set, starting by the middle value of it

> logarithmic scale