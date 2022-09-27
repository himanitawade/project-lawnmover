# project-lawnmover

Lori Cha
Email: lcha@csu.fullerton.edu

# The Alternating Disc Problem Definition
Input: A positive n and a list of 2n disks of alternating colors light-dark.
Output: A list of 2n disks where the first n disks are light and the next n disks are dark, and an integer m representing the number of swaps

## Psuedocode for Alg 1: Lawnmower
number of iterations = (ceileing of n) / 2  <br />
for i = 0 to (number of iterations - 1) do  <br />
  if i is even do  <br />
    for j = 0 to length(list) - 1 do  <br />
      if list[j] is not equal to list[j+1]
        swap them
       end if
     end for
  end if
   
  else
    for j = (length of the list - 1) to 0 do
      if (list[j] is not equal to list[j-1])
        swap them
      end if
     end for
   end else
end for

# Step Count

# Efficiency Class Using Limit Theorem

## Psuedocode for Alg 2
number of iterations = n + 1
for i = 0 to (# of iterations - 1) do
  for j = 0 to length(list) - 1 do
    if (list[j] not equal to list[j+1])
      swap
    end if
  end for
end for

# Step Count
