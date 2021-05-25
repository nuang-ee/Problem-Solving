class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> cur_gen = {"("};
        
        for (int i = 0; i < n*2 - 1; i++) {
            vector<string> next_gen;

            while (!cur_gen.empty()) {
                string cur = cur_gen.back(); cur_gen.pop_back();

                size_t opens = count(cur.begin(), cur.end(), '(');
                size_t unclosedOpens = opens - count(cur.begin(), cur.end(), ')');
                
                if (opens < n) next_gen.emplace_back(cur + '(');
                if (unclosedOpens >= 1) next_gen.emplace_back(cur + ')');
            }
            
            cur_gen = next_gen;
        }
        
        return cur_gen;
    }
};
