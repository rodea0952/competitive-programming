/*
https://algo-logic.info/trie-tree/, https://tiramistercp.hatenablog.com/entry/agc047-b より
Trie<26, 'a'> trie; のように宣言
文字の種類(char_size)、int 型で 0 に対応する文字(base)
insert(word): word を Trie 木に挿入
search(word): word が Trie 木にあるか判定
start_with(prefix): prefix が一致する単語が Trie 木にあるか判定
count(): 挿入した単語の個数
size(): Trie 木の頂点数
find(word): word の末尾の頂点番号
fill_cnt(): cnt, leaf_cnt を求める
*/

template <int char_size, int base>
struct Trie{
    struct Node{
        vector<int> nxt;    // 子の頂点番号（存在しなければ -1）
        vector<int> cnt;    // 文字 c を含む子孫の数
        vector<int> accept; // 末端がこの頂点になる単語の word_id を保存
        int c;              // この頂点の文字（base との差）
        int common;         // この頂点を共有している単語数
        int leaf_cnt;       // この頂点が持つ葉の数

        Node(int c_) : c(c_), common(0), leaf_cnt(0){
            nxt.assign(char_size, -1);
            cnt.assign(char_size, 0);
        }
    };

    vector<Node> nodes;
    int root;
    Trie() : root(-1){
        nodes.emplace_back(Node(root));
    }

    void insert(const string &word, int word_id){
        int node_id = 0;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - base;
            int &nxt_id = nodes[node_id].nxt[c];
            if(nxt_id == -1){
                // 次の頂点が存在しなければ追加
                nxt_id = nodes.size();
                nodes.emplace_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = nxt_id;
        }
        ++nodes[node_id].common;
        ++nodes[node_id].leaf_cnt;
        nodes[node_id].accept.emplace_back(word_id);
    }

    void insert(const string &word){
        insert(word, nodes[0].common);
    }

    bool search(const string &word, bool prefix = false){
        int node_id = 0;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - base;
            int &nxt_id = nodes[node_id].nxt[c];
            if(nxt_id == -1){ 
                // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = nxt_id;
        }
        return prefix ? true : nodes[node_id].accept.size() > 0;
    }

    bool start_with(const string &prefix){
        return search(prefix, true);
    }

    int count() const{
        return nodes[0].common;
    }

    int size() const{
        return nodes.size();
    }

    int find(const string &word) const{
        int node_id = 0;
        for(int i=0; i<word.size(); i++){
            int ci = word[i] - 'a';
            node_id = nodes[node_id].nxt[ci];
        }
        return node_id;
    }

    void fill_cnt(){
        for(int node_id=nodes.size()-1; node_id>=0; node_id--){
            auto &cur_node = nodes[node_id];
            for(int c=0; c<26; c++){
                int nxt_id = cur_node.nxt[c];
                if(nxt_id == -1) continue;

                auto child_node = nodes[nxt_id];
                cur_node.leaf_cnt += child_node.leaf_cnt;
                for(int d=0; d<26; d++){
                    cur_node.cnt[d] += child_node.cnt[d];
                }
            }

            // cur_node が c なら、全ての子孫は c を含む
            if(cur_node.c != -1){
                // 根ではないとき
                cur_node.cnt[cur_node.c] = cur_node.leaf_cnt;
            }
        }
    }
};