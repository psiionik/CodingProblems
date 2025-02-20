#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <regex>

using namespace std;

class Password {
    public:
        string byr;
        string iyr;
        string eyr;
        string hgt;
        string hcl;
        string ecl;
        string pid;
        string cid;

    Password() {
        this -> byr = "undefined";
        this -> iyr = "undefined";
        this -> eyr = "undefined";
        this -> hgt = "undefined";
        this -> hcl = "undefined";
        this -> ecl = "undefined";
        this -> pid = "undefined";
        this -> cid = "undefined";
    }

    void setByr(string byr){ this -> byr = byr; }
    void setIyr(string iyr){ this -> iyr = iyr; }
    void setEyr(string eyr){ this -> eyr = eyr; }
    void setHgt(string hgt){ this -> hgt = hgt; }
    void setHcl(string hcl){ this -> hcl = hcl; }
    void setEcl(string ecl){ this -> ecl = ecl; }
    void setPid(string pid){ this -> pid = pid; }
    void setCid(string cid){ this -> cid = cid; }

    bool isValid() {
        if (this -> byr != "undefined" && this -> iyr != "undefined" && this -> eyr != "undefined"
            && this -> hgt != "undefined" && this -> hcl != "undefined" && this -> ecl != "undefined"
            && this -> pid != "undefined") {
            return true;
        }

        return false;
    }

    bool byrValid() {
        if (this -> byr != "undefined") {
            int conv = stoi(this -> byr);
            if (conv >= 1920 && conv <= 2002) {
                return true;
            }
        }

        return false;
    }

    bool iyrValid() {
        if (this -> iyr != "undefined") {
            int conv = stoi(this -> iyr);
            if (conv >= 2010 && conv <= 2020) {
                return true;
            }
        }

        return false;
    }

    bool eyrValid() {
        if (this -> eyr != "undefined") {
            int conv = stoi(this -> eyr);
            if (conv >= 2020 && conv <= 2030) {
                return true;
            }
        }

        return false;
    }

    bool hgtValid() {
        if (this -> hgt != "undefined") {
            string unit = this -> hgt.substr(this -> hgt.size() - 2, 2);
            int conv = stoi(this -> hgt.substr(0, this -> hgt.size()  - 2));
            if (unit == "in") {
                if (conv >= 59 && conv <= 76) {
                    return true;
                }
            }
            if (unit == "cm") {
                if (conv >= 150 && conv <= 193) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hclValid() {
        if (this -> hcl != "undefined") {
            if (regex_match(this -> hcl, regex("#[a-f0-9]*"))) {
                return true;
            }
        }

        return false;
    }

    bool eclValid() {
        if (this -> ecl != "undefined") {
            if (this -> ecl == "amb" || this -> ecl == "blu" ||  this -> ecl == "brn" || this -> ecl == "gry" || 
                this -> ecl == "grn" || this -> ecl == "hzl" || this -> ecl == "oth") {
                    return true;
                }
        }

        return false;
    }

    bool pidValid() {
        if (this -> pid != "undefined") {
            if (regex_match(this -> pid, regex("[0-9]*")) && this -> pid.size() == 9) {
                return true;
            }
        }

        return false;
    }

    void printAll() {
        if (this -> byr != "undefined") {
            cout << "BYR: " + this -> byr << endl;
        }
        if (this -> iyr != "undefined") {
            cout << "IYR: " + this -> iyr << endl;
        }
        if (this -> eyr != "undefined") {
            cout << "EYR: " + this -> eyr << endl;
        }
        if (this -> hgt != "undefined") {
            cout << "HGT: " + this -> hgt << endl;
        }
        if (this -> hcl != "undefined") {
            cout << "HCL: " + this -> hcl << endl;
        }
        if (this -> ecl != "undefined") {
            cout << "ECL: " + this -> ecl << endl;
        }
        if (this -> pid != "undefined") {
            cout << "PID: " + this -> pid << endl;
        }
        if (this -> cid != "undefined") {
            cout << "CID: " + this -> cid << endl;
        }

        cout << "" << endl;
    }
};

void changePasswordFields(Password &pass, string key, string value) {
    if (key == "byr") {
        pass.setByr(value);
    }
    else if (key == "iyr") {
        pass.setIyr(value);
    }
    else if (key == "eyr") {
        pass.setEyr(value);
    }
    else if (key == "hgt") {
        pass.setHgt(value);
    }
    else if (key == "hcl") {
        pass.setHcl(value);
    }
    else if (key == "ecl") {
        pass.setEcl(value);
    }
    else if (key == "pid") {
        pass.setPid(value);
    }
    else if (key == "cid") {
        pass.setCid(value);
    }
}

int passportProcessingOne(vector<Password> &passwords) {
    int validPassports = 0;
    for (Password p : passwords) {
        if (p.isValid()) {
            validPassports++;
        }
    }

    return validPassports;
}

int passportProcessingTwo(vector<Password> &passwords) {
    int validPassports = 0;
    for (Password p : passwords){
        if (p.byrValid() && p.eclValid() && p.eyrValid() && p.hclValid() && p.hgtValid()
            && p.iyrValid() && p.pidValid())  {
                validPassports++;
            }
    }

    return validPassports;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ifstream myFile;
    myFile.open("./input.txt");

    vector<Password> passwords;
    string temp;
    Password pass;
    int count = 0;
    while(!myFile.eof()){
        getline(myFile, temp);
        if (temp == "") {
            count++;
            passwords.push_back(pass);
            pass = Password();
        }
        else {
            vector<string> space_split;
            string delim1 = " ";
            size_t start = 0;
            size_t end = temp.find(delim1);
            while (end != string::npos) {
                string extracted = temp.substr(start, end - start);
                space_split.push_back(extracted);
                start = end + delim1.length();
                end = temp.find(delim1, start);
            }
            space_split.push_back(temp.substr(start, end - start));
            
            for (string s : space_split) {
                string delim2 = ":";
                size_t startInner = 0;
                size_t endInner = s.find(delim2);
                while(endInner != string::npos) {
                    string innerExtractedFirst = s.substr(startInner, endInner - startInner);
                    string innerExtractedSecond = s.substr(endInner + 1, s.size() - (endInner + 1));
                    changePasswordFields(pass, innerExtractedFirst, innerExtractedSecond);
                    startInner = endInner + delim2.length();
                    endInner = s.find(delim2, startInner);
                }

                changePasswordFields(pass, s.substr(startInner, endInner - startInner), s.substr(endInner + 1, s.size() - (endInner + 1)));
            }
        }
    }
    passwords.push_back(pass);
    myFile.close();

    cout << passportProcessingOne(passwords) << endl;
    cout << passportProcessingTwo(passwords) << endl;

    return 0;
}