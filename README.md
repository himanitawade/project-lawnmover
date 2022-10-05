# project-lawnmover

Lori Cha <br />
Email: lcha@csu.fullerton.edu

Nicholas Caro <br />
Email: nicholascaro@csu.fullerton.edu

# The Alternating Disc Problem Definition
Input: A positive n and a list of 2n disks of alternating colors light-dark.  <br />
Output: A list of 2n disks where the first n disks are light and the next n disks are dark, and an integer m representing the number of swaps

# Algorithm 1: Lawnmower
We go left to right and compare every adjacent disk. We only swap if necessary. Then we go right to left. Comparing every adjacent disk and swaping them if necessary. Repeat this ceiling of $\frac{n}{2}$ times.

## Psuedocode for Alg 1: Lawnmower
number of iterations $= \frac{(ceiling\ of\ n)}{2}$  <br />
for i = 0 to (number of iterations - 1) do &emsp;&emsp; // $\frac{n}{2}$ iterations <br />
&emsp; for j = 0 to 2n-1 do &emsp;&emsp; // Going left to right <br /> 
&emsp;&emsp; if (list[j] == dark AND list[j+1] == light)  <br />
&emsp;&emsp;&emsp; Swap them <br />
&emsp;  end for <br />
<br /> 
&emsp; for j = 2n-1 to j = 0 do &emsp;&emsp; // Going back right to left <br />
&emsp;&emsp; if (list[j-1] == dark AND list[j] == light) <br />
&emsp;&emsp;&emsp; Swap them <br />
&emsp; end for <br />
end for

## Step Count
$S.C. = \frac{n}{2} (2n - 1( 2 + \max(0,1)) + 2n - 1(2 + \max(0,1)))$ <br />
&emsp; $= \frac{n}{2} (2n - 1( 2 + 1)) + 2n - 1(2 + 1))$ <br />
&emsp; $= \frac{n}{2} (2n - 1(3)) + 2n - 1(3))$ <br />
&emsp; $= \frac{n}{2} ((6n - 3) + (6n - 3))$ <br />
&emsp; $= \frac{n}{2} (12n - 6)$ <br />
&emsp; $= 6n^2 - 3n$ <br />

## Efficiency Class Using Limit Theorem
$\lim_{n \rightarrow \infty} \frac{6n^2 - 3n}{n^2} = 6$<br />
Since $6 \geq 0$ and $6$ is a constant, the Limit Theorem tells us that $6n^2 - 3n \in O(n^2)$. <br />
Thus, this implementation of this algorithm is $O(n^2)$.

# Algorithm 2: Alternate 
We go left to right and compare every **two** adjacent disks. We only make swaps if necessary. Note: It iterates over each pair.
# Psuedocode for Alg 2
number of iterations = n + 1  <br />
for i = 0 to (# of iterations - 1) do  <br />
&emsp; if i is even do <br />
&emsp;&emsp; for j = 0 to length(list) - 1 step 2 do  <br />
&emsp;&emsp;&emsp; if (list[j] == dark AND list[j+1] == light]) <br />
&emsp;&emsp;&emsp;&emsp; Swap them <br />
&emsp;&emsp; end for  <br />
<br />
&emsp; else do <br />
&emsp;&emsp; for j = 1 to length(list) - 2 step 2 do  <br />
&emsp;&emsp;&emsp; if (list[j] == dark AND list[j+1] == light) <br />
&emsp;&emsp;&emsp;&emsp; Swap them <br />
&emsp;&emsp; end for  <br />
end for  <br />

## Step Count
$S.C. = n( 1 + \max( \frac{n-1}{2}(2+1), \frac{n-2}{2} (2+1))$ <br />
&emsp; $= n( 1 + ( \frac{n-1}{2}(3))$ <br />
&emsp; $= n( 1 + ( \frac{3}{2}(n-1))$ <br />
&emsp; $= n + \frac{3}{2}n^2 - \frac{3}{2}n$ <br />
&emsp; $= \frac{3}{2}n^2 - \frac{1}{2}n$ <br />

## Efficiency Class Using Limit Theorem
$\lim_{n \rightarrow \infty} \frac{\frac{3}{2}n^2 - \frac{1}{2}n}{n^2} = \frac{3}{2}$ <br /> 
Since $\frac{3}{2} \geq 0$ and $\frac{3}{2}$ is a constant, the Limit Theorem tells us that $\frac{3}{2}n^2 - \frac{1}{2}n \in O(n^2)$ <br />
Thus, this implementation of this algorithm is $O(n^2)$. <br />
