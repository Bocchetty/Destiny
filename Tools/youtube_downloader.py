from pytube import YouTube

link = input("Enter the link:")
yt = YouTube(link)
print(yt.streams)

#Title
print("Title:", yt.title)

#Views
print("Number of views:", yt.views)

#Lenght
print("Lenght:", yt.length)

#Description
print("Description:", yt.description)

#Rating
print("Ratings: ",yt.rating)

ys = yt.streams.get_highest_resolution()

ys = yt.streams.get_by_itag('22')

ys.download()