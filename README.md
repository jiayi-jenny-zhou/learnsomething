# Intern Project Reading

We noticed that some people’s first reaction to not having a tool available (such as Taskfile) was to pip install it. The thing is, anytime you install a package with PIP, NPM, and most other package managers, they allow the published of the package to run arbitrary code on your machine. Now, since we don’t feel like removing BTC miners from our servers, we have added this assignment.
The two articles you have to read are linked below. Please PR this file with the answers.
- What file does PIP execute upon installing a package?

setup.py

- What are the payloads of malicious packages typically used for?

Things like stealing information, like Chrome's login credentials, credit card detais, etc. 

- How do the malware authors name their packages to get unsuspecting users to download them?  

Some name their packages as close spellings to legitimate packages that many people download. 

### Articles:  
- https://cyble.com/blog/over-45-thousand-users-fell-victim-to-malicious-pypi-packages/
- https://unit42.paloaltonetworks.com/malicious-packages-in-pypi/
