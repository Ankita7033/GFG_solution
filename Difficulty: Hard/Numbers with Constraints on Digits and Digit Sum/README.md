<h2><a href="https://www.geeksforgeeks.org/problems/special-digits--170647/1">Numbers with Constraints on Digits and Digit Sum</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given five integers <strong>n</strong>, <strong>a</strong>, <strong>b</strong>, <strong>c</strong>, and <strong>d,&nbsp;</strong></span><span style="font-size: 18px;">find the </span><strong style="font-size: 18px;">total </strong><span style="font-size: 18px;">number of best integers of length </span><strong style="font-size: 18px;">n</strong><span style="font-size: 18px;">.</span></p>
<ul>
<li><span style="font-size: 18px;">A good integer is an integer of length <strong>n</strong> such that every digit in its decimal representation is either <strong>a</strong> or <strong>b</strong>.</span></li>
<li><span style="font-size: 18px;">A <strong>best</strong> integer is a good integer whose sum of digits contains at least one of the digits <strong>c</strong> or <strong>d</strong> in its decimal representation.</span></li>
</ul>
<p><span style="font-size: 18px;">Since the answer can be very large, return it modulo <strong>10<sup>9</sup>+7</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 2, a = 1, b = 2, c = 3, d = 5
<strong>Output: </strong>2<strong>
Explanation: </strong>All 2-digit integers formed using only the digits 1 and 2 are 11, 12, 21, and 22. <br>Their digit sums are 2, 3, 3, and 4 respectively. <br>Since a best integer must have a digit sum containing either 3 or 5, only 12 and 21 satisfy the condition. <br>Therefore, the answer is 2.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 1, a = 1, b = 1, c = 2, d = 3
<strong>Output: </strong>0<strong>
Explanation: </strong></span><span style="font-size: 18px;">The only 1-digit integer that can be formed using the digits 1 and 1 is 1. <br>Its digit sum is also 1, which does not contain either c = 2 or d = 3. <br>Therefore, there are no best integers, so the answer is 0.</span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">n = 4, a = 6, b = 7, c = 5, d = 3
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">4</span><strong style="font-size: 18px;">
Explanation: </strong><span style="font-size: 18px;">All 4-digit integers formed using only the digits 6 and 7 are considered good integers. <br>Among them, the integers 6667, 6676, 6766, and 7666 have a digit sum of 25. <br>Since the decimal representation of 25 contains C = 5, these integers are best integers. <br>Therefore, the total number of best integers is 4.</span>
</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ a, b, c, d ≤ 9<br>1 ≤ n ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Combinatorial</code>&nbsp;<code>Mathematics</code>&nbsp;