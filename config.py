# -*- coding: utf-8 -*-

LIBRARY_DIR = "library/"

CODE_LIST = [
    ("Template",
     [
        ("template/template.cpp",
         u"""全部インクルードするとコンパイルが微妙に重いので一部だけ入れてる．
         range は range-based for 用のクラス．
         range(n) は 0 .. (n-1) まで，range(i, n) は i .. (n-1) までイテレートする．""",
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

        ("structure/bit.cpp",
         u"""よくある Binary Indexed Tree．クラス内の型 T には操作対象の配列の要素の型を指定する．
         <ul>
         <li>init : サイズと各要素の初期値(0に相当する値)を指定して初期化する．</li>
         <li>add : 指定された要素に値を足し込む．要素は 0-indexed で指定する．計算時間は O(log n)．</li>
         <li>sum : 0 .. i までの要素の和を計算し出力する．計算時間は O(log n)．</li>
         </ul>""",
         None),

        ("structure/rmq.cpp",
         u"""よくある Range Minimum/Maximum Query．クラス内の型 T には操作対象の配列の要素の型を指定する．
         <ul>
         <li>init  : サイズとオペレータを指定して初期化する．サイズは木のサイズではなく操作対象の配列のサイズを指定する．サイズは実装の都合で2のべき乗でなければならない．オペレータには区間に適用する functional オブジェクトを指定する．</li>
         <li>overwrite : 指定された要素の値を更新する．要素は 0-indexed で指定する．計算時間は O(log n)．</li>
         <li>query : [fr, to) の要素にオペレータを適用したときの値を出力する．計算時間は O(log n)．</li>
         </ul>
         内部の実装においては data[1] が root を指している．
         data[i] の子は data[2 * i + 0], data[2 * i + 1] である．
         data[i] の親は data[i / 2] である．
         操作対象の配列に直接対応する要素は data[n + i] (i=0,1,...,n-1) である．
         """,
         None),

        ("structure/segtree.cpp",
         u"""区間ごとの更新/クエリに対応したセグメント木．クラス内の型 T には操作対象の配列の要素の型を，DT にはディレイ情報を表す型を指定する．
         色んな用途向けに結構抽象化して書いてしまっているためちょっと使いづらい？かもしれないので注意．
         <ul>
         <li>init  : サイズと要素更新用オペレータ，ディレイ更新用オペレータを指定して初期化する．サイズは木のサイズではなく操作対象の配列のサイズを指定する．サイズは実装の都合で2のべき乗でなければならない．要素更新用オペレータには区間に適用する functional オブジェクトを指定する．ディレイ更新用オペレータにはディレイを親から子に受け継ぐ処理を記述した functional オブジェクトを指定する．(加算/変更それぞれに対応する functional オブジェクトは Usage を参照)</li>
         <li>update : 区間 [fr, to) までを更新する．更新の内容はオペレータ op に依存する．計算時間は O(log n)．</li>
         <li>query : [fr, to) の要素にオペレータ op を適用したときの値を出力する．計算時間は O(log n)．</li>
         </ul>
         内部の実装においては data[1] が root を指している．
         data[i] の子は data[2 * i + 0], data[2 * i + 1] である．
         data[i] の親は data[i / 2] である．
         操作対象の配列に直接対応する要素は data[n + i] (i=0,1,...,n-1) である．
         """,
         "structure/segtree_usage.cpp"),

        ("structure/dice.cpp",
         u"""さいころ．各変数の対応とかはコメントのアスキーアート参照．""",
         None),

        ("structure/rbst.cpp",
         u"""Randomized Binary Search Tree．split/merge ベースの乱択平衡二分探索木．他の実装とは違い，頂点のポインタを保持する形で実装している．
         各頂点は頂点の値(val)，付加情報(info)，サブツリーのサイズ(size)，左右のサブツリーのポインタ(l, r) を持っている．
         マージの都合上，info と val は同じ型でないといけない．
         Max / Min / Sum などのクエリを行いたい場合，クラス内の op 関数を書き換える．これは2つのノード同士をマージする場合の処理を記述する．
         <ul>
         <li>RBST(コンストラクタ) : 初期値を指定して初期化する．</li>
         <li>split : 指定した位置で木を2分割する．</li>
         <li>merge : 2つの木をマージする．</li>
         <li>query : 指定した区間について op 関数を適応した値を返す．</li>
         <li>insert/erase : 指定した位置に挿入/削除する．</li>
         <li>at : 要素へのアクセス．</li>
         </ul>
         """,
         "structure/rbst_usage.cpp"),
     ]
    ),

    ("Math",
     [
     ]
    ),

    ("Graph Algorithm",
     [
     ]
    ),

    ("Geometry",
     [
     ]
    ),
]
