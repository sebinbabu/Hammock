# Hammock

A fast and nifty little crawler.

![Hammock](https://raw.githubusercontent.com/sebinbabu/Hammock/master/web-crawler.jpg)


### Prerequisites

You need to install the following two packages: 
* curl / libcurl : Developer’s libraries for curl

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. Open up your terminal after installing the prerequisites and put these commands.

```
git clone https://github.com/sebinbabu/Hammock.git
cd Hammock
make
sudo make install
```
## Usage

Use the ```hammock help``` command to get instructions.

#### Example usage

* ```hammock init``` : initializes the current working directory as a Hammock directory
* ```hammock depth 5``` : sets the crawl depth of the crawler to 5 levels of recursion
* ```hammock add http:///www.google.com/``` : adds Google's homepage to the crawl queue
* ```hammock add http://github.com/``` : adds Github's homepage to the crawl queue
* ```hammock crawl``` : starts the crawler on the queue

## Authors / Credits

* **Sebin Babu** - *Initial work* - [Sebin Babu](https://github.com/sebinbabu)
* **Michael Kowalczyk** - *Work on htmlstreamparser* - [htmlstreamparser](https://code.google.com/archive/p/htmlstreamparser/)

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE.md](LICENSE.md) file for details

