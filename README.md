# project-lawnmover

Lori Cha
Email: lcha@csu.fullerton.edu

Nicholas Caro
Email: nicholascaro@csu.fullerton.edu

# The Alternating Disc Problem Definition
Input: A positive n and a list of 2n disks of alternating colors light-dark.  <br />
Output: A list of 2n disks where the first n disks are light and the next n disks are dark, and an integer m representing the number of swaps

## Psuedocode for Alg 1: Lawnmower
number of iterations $= \frac{(ceiling\ of\ n)}{2}$  <br />
for i = 0 to (number of iterations - 1) do  <br />
&emsp;  if i is even do  <br />
&emsp;&emsp;    for j = 0 to length(list) - 1 do  <br />
&emsp;&emsp;&emsp;     if list[j] is not equal to list[j+1]  <br />
&emsp;&emsp;&emsp;&emsp;        swap them  <br />
&emsp;&emsp;&emsp;       end if  <br />
&emsp;&emsp;     end for  <br />
&emsp;  end if  <br />
   
&emsp;  else  <br />
&emsp;&emsp;    for j = (length of the list - 1) to 0 do  <br />
&emsp;&emsp;&emsp;     if (list[j] is not equal to list[j-1])  <br />
&emsp;&emsp;&emsp;&emsp;       swap them  <br />
&emsp;&emsp;&emsp;     end if  <br />
&emsp;&emsp;     end for  <br />
&emsp;  end else  <br />
end for  <br />

## Step Count
$S.C. = \frac{n}{2} (1 + \max(n+2, n+2))$ <br />
&emsp; $\ = \frac{n}{2} * (3 + n)$ <br />
&emsp; $\ = \frac{3}{2}n + \frac{1}{2} n^2$

## Efficiency Class Using Limit Theorem
$S.C. = \ = \frac{3}{2}n + \frac{1}{2} n^2$ <br />
&emsp; $= \lim_{n \rightarrow \infty} \frac{ \frac{3}{2}n + \frac{1}{2} n^2}{n^2}$ <br />
&emsp; $= \frac{1}{2}$<br />
Since $\frac{1}{2} \geq 0$ and $\frac{1}{2}$ is a constant, the Limit Theorem tells us that $\frac{3}{2}n + \frac{1}{2} n^2 \in O(n^2)$. <br />
Thus, this implementation of this algorithm is $O(n^2)$.

# Psuedocode for Alg 2
number of iterations = n + 1  <br />
for i = 0 to (# of iterations - 1) do  <br />
&emsp;  for j = 0 to length(list) - 1 do  <br />
&emsp;&emsp;    if (list[j] not equal to list[j+1])  <br />
&emsp;&emsp;&emsp;      swap  <br />
&emsp;&emsp;    end if  <br />
&emsp;  end for  <br />
end for  <br />

## Step Count
$S.C. = n+1 \[2n -1 (1+1)\]$ <br />
&emsp; $= (n+1) \[2(2n-1) \]$ <br />
&emsp; $= (n+1) (4n-2)$ <br />
&emsp; $= 4n^2 -2n + 4n -2$ <br />
&emsp; $= 4n^2 + 2n -2$ <br />

## Efficiency Class Using Limit Theorem
$S.C. = 4n^2 + 2n -2$ <br />
&emsp; $= \lim_{n \rightarrow \infty} \frac{4n^2 + 2n -2}{n^2}$ <br />
&emsp; $= 4$ <br /> 
Since $4 \geq 0$ and $4$ is a constant, the Limit Theorem tells us that $4n^2 + 2n -2 \in O(n^2)$ <br />
Thus, this implementation of this algorithm is $O(n^2)$. <br />
