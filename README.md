# project-lawnmover

Lori Cha
Email: lcha@csu.fullerton.edu

# The Alternating Disc Problem Definition
Input: A positive n and a list of 2n disks of alternating colors light-dark.  <br />
Output: A list of 2n disks where the first n disks are light and the next n disks are dark, and an integer m representing the number of swaps

## Psuedocode for Alg 1: Lawnmower
number of iterations = (ceileing of n) / 2  <br />
for i = 0 to (number of iterations - 1) do  <br />
  if i is even do  <br />
    for j = 0 to length(list) - 1 do  <br />
      if list[j] is not equal to list[j+1]  <br />
        swap them  <br />
       end if  <br />
     end for  <br />
  end if  <br />
   
  else  <br />
    for j = (length of the list - 1) to 0 do  <br />
      if (list[j] is not equal to list[j-1])  <br />
        swap them  <br />
      end if  <br />
     end for  <br />
   end else  <br />
end for  <br />

# Step Count

# Efficiency Class Using Limit Theorem

## Psuedocode for Alg 2
number of iterations = n + 1  <br />
for i = 0 to (# of iterations - 1) do  <br />
  for j = 0 to length(list) - 1 do  <br />
    if (list[j] not equal to list[j+1])  <br />
      swap  <br />
    end if  <br />
  end for  <br />
end for  <br />

# Step Count
