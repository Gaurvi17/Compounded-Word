<h1>COMPOUNDED WORD</h1>
<br/>
<br/>
<h1>INTUTION:</h1>
<br/>
<p>I have used <b>tries data structure</b> for finding the longest compounded word. A compounded word is a word that can be constructed by combining (concatenating) shorter words also found in the same input file</p>
<br/>
<h1>APPROACH:</h1>
<p>For each word in the vector, it checks if the word is compounded by using the relevant used made function. This function recursively breaks down the word into prefixes and suffixes, checking if both parts are present in the trie.It also records the time taken to process the input file using the `chrono` library.</p>