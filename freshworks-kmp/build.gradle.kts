import com.android.build.api.dsl.androidLibrary
import org.jetbrains.kotlin.gradle.dsl.JvmTarget

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.android.kotlin.multiplatform.library)
    alias(libs.plugins.vanniktech.mavenPublish)
    alias(libs.plugins.kotlinCocoapods)
}

group = "io.github.aditya-gupta99"
version = "1.0.5"

kotlin {
    androidLibrary {
        namespace = "com.aditya.gupta99.freshworks"
        compileSdk = libs.versions.android.compileSdk.get().toInt()
        minSdk = libs.versions.android.minSdk.get().toInt()

        compilations.configureEach {
            compilerOptions.configure {
                jvmTarget.set(
                    JvmTarget.JVM_11
                )
            }
        }
    }
    iosX64()
    iosArm64()
    iosSimulatorArm64()


    cocoapods {
        summary = "KMP Freshchat wrapper"
        homepage = "https://github.com/your-org/freshchat-kmp"
        version = "1.0.0"
        ios.deploymentTarget = "13.0"
        name = "FreshchatKMP"

        pod("FreshchatSDK") {
            // Uses SPM-compatible pod from Freshworks
            // Alternatively: version = "~> 10.0"
        }

        framework {
            baseName = "FreshchatKMP"
            isStatic = true      // static embedding
            linkerOpts("-ObjC")
        }
    }

    sourceSets {
        androidMain.dependencies {
            // Freshchat Android SDK via JitPack
            implementation(libs.freshchat.android)

            // FCM (for push token)
            implementation(libs.firebase.messaging.ktx)

            // LocalBroadcastManager
            implementation(libs.localbroadcastmanager)

            // Coroutines Android
            implementation(libs.kotlinx.coroutines.android)
        }
        commonMain.dependencies {
            //put your multiplatform dependencies here
        }

        commonTest.dependencies {

        }
    }
}

mavenPublishing {
    publishToMavenCentral()

    signAllPublications()

    coordinates(group.toString(), "freshworks-kmp", version.toString())

    pom {
        name = "Freshworks KMP"
        description = "A multiplatform library for Freshworks"
        inceptionYear = "2025"
        url = "https://github.com/Aditya-gupta99/Freshworks-kmp.git"
        licenses {
            license {
                name = "MIT"
                url = "https://opensource.org/licenses/MIT"
                distribution = "ZZZ"
            }
        }
        developers {
            developer {
                id = "Aditya-gupta99"
                name = "Aditya Gupta"
                url = "https://github.com/Aditya-gupta99"
            }
        }
        scm {
            url = "https://github.com/Aditya-gupta99/Freshworks-kmp.git"
        }
    }
}