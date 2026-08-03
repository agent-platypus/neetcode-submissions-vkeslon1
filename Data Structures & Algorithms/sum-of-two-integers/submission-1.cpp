class Solution {
public:
    int getSum(int a, int b) {
        
        int total = 0;
        int carryin = 0;
        int sum = 0;

        for(int i = 0; i < sizeof(int) * 8; i++) {

            int mask = 1 << i;
            int a_op = a & mask;
            int b_op = b & mask;

            int axorb = a_op ^ b_op;
            int aandb = a_op & b_op;


            sum = axorb ^ carryin;
            carryin = aandb | (carryin & axorb);

            carryin = carryin << 1;

            total |= sum;

            

        }
        return total |= carryin;
    }

};
