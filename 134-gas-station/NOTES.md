if total gas is greater than or equal to cost, then there has to be a solution;
at any station, curr(gas[i]-cost[i]) will be the amount of gas remaining, if at any station, curr<0, then we know it's not possible, so we'll just visit the next station;
Then finally if sum>=0, then sol exists and its the index :))