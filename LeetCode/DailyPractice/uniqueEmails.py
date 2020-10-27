"""
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local
name part of an email address, mail sent there will be forwarded to the same address without dots in the local
name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address. 
(Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.
(Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 
"""

def numUniqueEmails(emails):
    result = 0
    local = []
    domain_set = set()
    for email in emails:
        res = email.split('@')
        t = res[0].split("+")
        t = t[0].replace(".", "")
        t += "@"
        t += res[1]
        domain_set.add(t)

    return len(domain_set)

def main():

    # Test 1: Should return 2

    # emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]

    # Test 2: Should return 2

    emails = ["test.email+alex@leetcode.com","test.email.leet+alex@code.com"]

    print(numUniqueEmails(emails))


main()