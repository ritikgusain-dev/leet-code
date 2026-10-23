class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {

                string str1 = words[i];
                string str2 = words[j];

                if (str1.size() > str2.size())
                    continue;

                // Check whether str1 is a prefix of str2
                if (str2.substr(0, str1.size()) != str1)
                    continue;

                // Check whether str1 is a suffix of str2
                if (str2.substr(str2.size() - str1.size()) != str1)
                    continue;

                count++;
            }
        }

        return count;
    }
};
