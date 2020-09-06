---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# {{ site.title }}

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions)
<a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

{% if site.github.project_tagline %}{{ site.github.project_tagline }}{% else %}This documentation is automatically generated by <a href="https://github.com/online-judge-tools/verification-helper">online-judge-tools/verification-helper</a>.{% endif %}

## Library Files

<div id="dd743839bbbccf6b9f92c191458344b7"></div>

### _template

* :question: <a href="library/_template/_template.cpp.html">_template/_template.cpp</a>


<div id="f8b0b924ebd7046dbfa85a856e4682c8"></div>

### graph

* :heavy_check_mark: <a href="library/graph/_graph-template.cpp.html">graph/_graph-template.cpp</a>
* :heavy_check_mark: <a href="library/graph/bellman-ford.cpp.html">graph/bellman-ford.cpp</a>
* :heavy_check_mark: <a href="library/graph/find-directed-graph-cycle.cpp.html">graph/find-directed-graph-cycle.cpp</a>
* :heavy_check_mark: <a href="library/graph/get-shortest-path.cpp.html">graph/get-shortest-path.cpp</a>
* :heavy_check_mark: <a href="library/graph/scc.cpp.html">graph/scc.cpp</a>
* :heavy_check_mark: <a href="library/graph/topological-sort.cpp.html">graph/topological-sort.cpp</a>


<div id="7e676e9e663beb40fd133f5ee24487c2"></div>

### math

* :warning: <a href="library/math/prime-factorization.cpp.html">math/prime-factorization.cpp</a>
* :x: <a href="library/math/prime-sieve.cpp.html">math/prime-sieve.cpp</a>


<div id="5e2bab0ecb94c4ea40777733195abe1b"></div>

### others

* :warning: <a href="library/others/dice.cpp.html">others/dice.cpp</a>


<div id="07414f4e15ca943e6cde032dec85d92f"></div>

### structure

* :heavy_check_mark: <a href="library/structure/union-find.cpp.html">structure/union-find.cpp</a>


## Verify Files

* :heavy_check_mark: <a href="verify/test/bellman-ford.test.cpp.html">test/bellman-ford.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/find-directed-graph-cycle.test.cpp.html">test/find-directed-graph-cycle.test.cpp</a>
* :x: <a href="verify/test/prime-sieve.test.cpp.html">test/prime-sieve.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/scc.test.cpp.html">test/scc.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/topological-sort.test.cpp.html">test/topological-sort.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/union-find.test.cpp.html">test/union-find.test.cpp</a>

