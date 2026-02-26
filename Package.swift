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
            url: "https://github.com/Aditya-gupta99/Freshworks-kmp/releases/download/1.0.7/FreshchatKMP.xcframework.zip",
            checksum: "80c27ea2aab908d0e63aaefefb6e7ea5fe39c6aecbccd445366cb2ad08fee5c2"
        )
    ]
)
