CP331 - Assignment 2#  
Due 5:30 pm, Thursday, March 16 , 2017\. Submit PDF file and source code by email.  

Rules for submitting can be found in the course outline. Assignment is to be done by groups of three students.  

Each group should contact the instructor for information on how to access the virtual machine on which the code should be tested.  

* * *

(problem from P. Pacheco, Parallel Programming with MPI)  
A more accurate alternative to the trapezoidal rule is Simpson's rule. The basic idea is to approximate the graph of f(x) by arcs of parabolas rather than line segments. Suppose that p < q are real numbers, and let r be the midpoint of the segment [p,q]. If we let h = (q-p)/2, then the equation for the parabola passing through the points (p,f(p)),(r,f(r)), and (q,f(q)) is  

![Equation 1](https://bohr.wlu.ca/ppomorski/eq1_ps1.png)  

If we integrate this from p to q, we get  

![Equation 2](https://bohr.wlu.ca/ppomorski/eq2_ps1.png)   

Thus, if we use the same notation that we used in our discussion of the trapezoidal rule and assume that n, the number of subintervals of [a,b] , is even, we can approximate  

![Equation 3](https://bohr.wlu.ca/ppomorski/eq3_ps1.png)  

Write 3 programs:  

1\. a serial program  
2\. an MPI parallel program  
3\. an OpenMP parallel program  

that use Simpson's rule to estimate the integral of  
![Equation 4](eq4_ps1.png)  
for some function f of your choice that can be integrated exactly, allowing you to check your answer.  

You can assume that the number of processes or threads is less than n/2\. However, do **not** assume that n/2 divided by the number of processes is an integer. Aim to assign the same amount of work to all processes or threads, as far as that is reasonably possible.  

4\. Time all three codes to study their performance on hopper, your own laptop/desktop, and/or other multicore computers indicated by the instructor.
