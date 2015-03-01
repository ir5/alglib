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
         None),

        ("structure/rmq.cpp",
         u"""よくある Range Minimum/Maximum Query．クラス内の型 T には配列の要素の型を指定する．
         <ul>
         <li>init  : サイズとオペレータを指定して初期化する．サイズは木のサイズではなく操作対象の配列のサイズを指定する．サイズは実装の都合で2のべき乗でなければならない．オペレータには区間に適用する functional オブジェクトを指定する．</li>
         <li>overwrite : 指定された要素の値を更新する．計算時間は O(log n)．</li>
         <li>query : [fr, to) の要素にオペレータを適用したときの値を出力する．計算時間は O(log n)．</li>
         </ul>
         内部の実装においては data[1] が root を指している．
         data[i] の子は data[2 * i + 0], data[2 * i + 1] である．
         data[i] の親は data[i / 2] である．
         操作対象の配列に直接対応する要素は data[n + i] (i=0,1,...,n-1) である．
         """,
         None),
     ]
    )
]
