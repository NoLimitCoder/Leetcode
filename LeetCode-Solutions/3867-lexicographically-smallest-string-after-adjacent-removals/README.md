<p>You are given a string <code>s</code> consisting of lowercase English letters.</p>

<p>You can perform the following operation any number of times (including zero):</p>

<ul>
	<li>Remove <strong>any</strong> pair of <strong>adjacent</strong> characters in the string that are <strong>consecutive</strong> in the alphabet, in either order (e.g., <code>&#39;a&#39;</code> and <code>&#39;b&#39;</code>, or <code>&#39;b&#39;</code> and <code>&#39;a&#39;</code>).</li>
	<li>Shift the remaining characters to the left to fill the gap.</li>
</ul>

<p>Return the <strong><span data-keyword="lexicographically-smaller-string">lexicographically smallest</span></strong> string that can be obtained after performing the operations optimally.</p>

<p><strong>Note:</strong> Consider the alphabet as circular, thus <code>&#39;a&#39;</code> and <code>&#39;z&#39;</code> are consecutive.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;a&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Remove <code>&quot;bc&quot;</code> from the string, leaving <code>&quot;a&quot;</code> as the remaining string.</li>
	<li>No further operations are possible. Thus, the lexicographically smallest string after all possible removals is <code>&quot;a&quot;</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;bcda&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>​​​​​​​</strong>Remove <code>&quot;cd&quot;</code> from the string, leaving <code>&quot;ba&quot;</code> as the remaining string.</li>
	<li>Remove <code>&quot;ba&quot;</code> from the string, leaving <code>&quot;&quot;</code> as the remaining string.</li>
	<li>No further operations are possible. Thus, the lexicographically smallest string after all possible removals is <code>&quot;&quot;</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;zdce&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;zdce&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Remove <code>&quot;dc&quot;</code> from the string, leaving <code>&quot;ze&quot;</code> as the remaining string.</li>
	<li>No further operations are possible on <code>&quot;ze&quot;</code>.</li>
	<li>However, since <code>&quot;zdce&quot;</code> is lexicographically smaller than <code>&quot;ze&quot;</code>, the smallest string after all possible removals is <code>&quot;zdce&quot;</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 250</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
