# M MPEG-4 part 14

MP4, which stands for MPEG-4 Part 14, is a digital multimedia container format most commonly used to store video and audio data. It is a versatile format that can also hold other types of data, such as subtitles and still images. MP4 files are commonly used for streaming videos over the Internet.

The MP4 file structure is based on the ISO Base Media File Format (ISOBMFF), which is a hierarchical structure composed of atoms, also known as boxes. Each atom has a unique four-character identifier (FourCC) that identifies its type and a size field that indicates its length. Atoms can contain other atoms or data, forming a nested tree-like structure.

## The root level of an MP4 file typically contains the following atoms:

<ul>
    <li>ftyp: This atom contains information about the file type, including the major brand, minor brand, and compatible brands.
    </li>
    <li>
    moov: This atom contains all the metadata for the movie, such as the movie duration, track information, and timing information.
    </li>
    <li>
    moof: This atom contains media fragments, which are chunks of compressed media data.
    </li>
    <li>
    mdat: This atom contains the raw media data, such as the encoded video and audio streams.
    </li>
    <li>
    pdin: This atom is optional and contains information for progressive download of video content.
    </li>
    <li>
    meta: This atom contains additional metadata, such as tags, ratings, and artwork.
    </li>
</ul>
<h2> The moov atom is further divided into subatoms that provide specific metadata about the movie. These subatoms include:
</h2>
<ul>
<li>
    mvhd: This atom contains header information for the movie, such as the creation and modification dates, duration, and playback rate.
</li>
<li>
    trak: This atom contains information about a specific track, such as the track type (audio or video), sample description, and track editing information.
</li>
<li>
    mdia: This atom contains information about the media within a track, such as the media type, handler type, and media timescale.
</li>
<li>
    minf: This atom contains information about the media format and data references.
</li>
<li>
    stbl: This atom contains sample table information, which maps media samples to their corresponding timestamps and offsets.
</li>

</ul>
The moof atom contains one or more moof fragments, each of which contains a set of media fragments. Each media fragment is identified by a track ID and a sequence number. The mdat atom contains the raw media data for the movie, which is organized according to the track IDs and sequence numbers specified in the moof atom.

The MP4 file structure is extensible, meaning that new atoms can be defined and added to the format to accommodate new features and technologies. This extensibility has made MP4 a popular and widely adopted format for multimedia content.
