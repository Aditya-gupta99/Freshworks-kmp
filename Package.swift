import PackageDescription

let package = Package(
    name: "FreshchatKMP",
    platforms: [.iOS(.v13)],
    products: [
        .library(
            name: "FreshchatKMP",
            targets: ["FreshchatKMP"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "FreshchatKMP",
            url: "https://github.com/Aditya-gupta99/Freshworks-kmp/releases/download/1.0.5/FreshchatKMP.xcframework.zip",
            checksum: "PASTE_YOUR_CHECKSUM_HERE"
        )
    ]
)
