# -*- coding: utf-8 -*-

LIBRARY_DIR = "library/"

CODE_LIST = [
    ("Template",
     [
        ("template/template.cpp",
         u"range(n) は 0 .. (n-1) まで，range(i, n) は i .. (n-1) までイテレートする．",
         None)
     ]
    ),

    ("Data Structure",
     [
        ("structure/uf.cpp",
         u"""よくある Union Find．
         <ul>
         <li>init  : サイズを指定して初期化する．</li>
         <li>root  : 指定された頂点が属する連結成分の代表点を返す．</li>
         <li>find  : 2つの頂点が同一の連結成分に属するかどうか返す．</li>
         <li>merge : 指定された頂点が属する2つの連結成分をマージする．</li>
         </ul>""",
         None)
     ]
    )
]
