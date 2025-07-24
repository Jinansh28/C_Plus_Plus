"use client"

import { useState, useEffect } from "react"
import { Button } from "@/components/ui/button"
import { Card, CardDescription, CardHeader, CardTitle } from "@/components/ui/card"
import { Badge } from "@/components/ui/badge"
import {
  Leaf,
  Smartphone,
  Globe,
  Wifi,
  Camera,
  Users,
  Target,
  ArrowRight,
  Menu,
  X,
  CheckCircle,
  Zap,
  Shield,
  Heart,
} from "lucide-react"

export default function HomePage() {
  const [isMenuOpen, setIsMenuOpen] = useState(false)
  const [activeSection, setActiveSection] = useState("home")

  useEffect(() => {
    const handleScroll = () => {
      const sections = ["home", "about", "features", "how-it-works", "impact"]
      const scrollPosition = window.scrollY + 100

      for (const section of sections) {
        const element = document.getElementById(section)
        if (element) {
          const offsetTop = element.offsetTop
          const offsetHeight = element.offsetHeight

          if (scrollPosition >= offsetTop && scrollPosition < offsetTop + offsetHeight) {
            setActiveSection(section)
            break
          }
        }
      }
    }

    window.addEventListener("scroll", handleScroll)
    return () => window.removeEventListener("scroll", handleScroll)
  }, [])

  const scrollToSection = (sectionId: string) => {
    const element = document.getElementById(sectionId)
    if (element) {
      element.scrollIntoView({ behavior: "smooth" })
    }
    setIsMenuOpen(false)
  }

  const navItems = [
    { id: "home", label: "Home" },
    { id: "about", label: "About" },
    { id: "features", label: "Features" },
    { id: "how-it-works", label: "How It Works" },
    { id: "impact", label: "Impact" },
  ]

  return (
    <div className="min-h-screen bg-white">
      {/* Navigation */}
      <nav className="fixed top-0 left-0 right-0 bg-white/95 backdrop-blur-sm border-b border-green-100 z-50">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="flex justify-between items-center h-16">
            <div className="flex items-center space-x-2">
              <Leaf className="h-8 w-8 text-green-600" />
              <span className="font-bold text-xl text-gray-900">CropAI</span>
            </div>

            {/* Desktop Navigation */}
            <div className="hidden md:flex space-x-8">
              {navItems.map((item) => (
                <button
                  key={item.id}
                  onClick={() => scrollToSection(item.id)}
                  className={`text-sm font-medium transition-colors hover:text-green-600 ${
                    activeSection === item.id ? "text-green-600" : "text-gray-700"
                  }`}
                >
                  {item.label}
                </button>
              ))}
            </div>

            {/* Mobile menu button */}
            <div className="md:hidden">
              <button onClick={() => setIsMenuOpen(!isMenuOpen)} className="text-gray-700 hover:text-green-600">
                {isMenuOpen ? <X className="h-6 w-6" /> : <Menu className="h-6 w-6" />}
              </button>
            </div>
          </div>
        </div>

        {/* Mobile Navigation */}
        {isMenuOpen && (
          <div className="md:hidden bg-white border-t border-green-100">
            <div className="px-2 pt-2 pb-3 space-y-1">
              {navItems.map((item) => (
                <button
                  key={item.id}
                  onClick={() => scrollToSection(item.id)}
                  className={`block px-3 py-2 text-base font-medium w-full text-left transition-colors hover:text-green-600 hover:bg-green-50 rounded-md ${
                    activeSection === item.id ? "text-green-600 bg-green-50" : "text-gray-700"
                  }`}
                >
                  {item.label}
                </button>
              ))}
            </div>
          </div>
        )}
      </nav>

      {/* Home Section */}
      <section id="home" className="relative min-h-screen flex items-center justify-center overflow-hidden">
        {/* Background Image */}
        <div
          className="absolute inset-0 bg-cover bg-center bg-no-repeat"
          style={{
            backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.4), rgba(0, 0, 0, 0.4)), url('/placeholder.svg?height=1080&width=1920')`,
          }}
        />

        {/* Content */}
        <div className="relative z-10 text-center text-white px-4 sm:px-6 lg:px-8 max-w-4xl mx-auto">
          <Badge className="mb-6 bg-green-600 hover:bg-green-700 text-white px-4 py-2">
            Samsung Solve for Tomorrow 2025
          </Badge>

          <h1 className="text-4xl sm:text-5xl lg:text-6xl font-bold mb-6 leading-tight">
            AI-Powered Crop Disease Identifier
            <span className="block text-green-400 mt-2">for Sustainable Agriculture</span>
          </h1>

          <p className="text-xl sm:text-2xl mb-8 text-gray-200 max-w-3xl mx-auto">
            Empowering Farmers with AI to Fight Crop Diseases
          </p>

          <div className="flex flex-col sm:flex-row gap-4 justify-center">
            <Button
              size="lg"
              className="bg-green-600 hover:bg-green-700 text-white px-8 py-3 text-lg"
              onClick={() => scrollToSection("features")}
            >
              Try the App <ArrowRight className="ml-2 h-5 w-5" />
            </Button>
            <Button
              size="lg"
              variant="outline"
              className="border-white text-white hover:bg-white hover:text-gray-900 px-8 py-3 text-lg bg-transparent"
              onClick={() => scrollToSection("about")}
            >
              Learn More
            </Button>
          </div>
        </div>
      </section>

      {/* About Section */}
      <section id="about" className="py-20 bg-gray-50">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="text-center mb-16">
            <h2 className="text-3xl sm:text-4xl font-bold text-gray-900 mb-4">About the Project</h2>
            <p className="text-xl text-gray-600 max-w-3xl mx-auto">
              Addressing the critical challenge of crop disease detection in rural farming communities
            </p>
          </div>

          <div className="grid md:grid-cols-2 gap-12 items-center">
            <div>
              <h3 className="text-2xl font-bold text-gray-900 mb-6">The Problem</h3>
              <p className="text-gray-600 mb-6 leading-relaxed">
                Crop diseases cause significant losses in agricultural productivity, particularly affecting smallholder
                farmers in rural areas who lack access to expert agricultural advice. Early detection and proper
                identification of crop diseases are crucial for preventing widespread crop failure and ensuring food
                security.
              </p>

              <h3 className="text-2xl font-bold text-gray-900 mb-6">Our Mission</h3>
              <p className="text-gray-600 mb-6 leading-relaxed">
                To democratize access to agricultural expertise by providing farmers with an AI-powered tool that can
                instantly identify crop diseases using just a smartphone camera, enabling timely intervention and
                sustainable farming practices.
              </p>

              <div className="space-y-4">
                <div className="flex items-start space-x-3">
                  <Target className="h-6 w-6 text-green-600 mt-1 flex-shrink-0" />
                  <div>
                    <h4 className="font-semibold text-gray-900">Early Disease Detection</h4>
                    <p className="text-gray-600">Identify diseases before they spread and cause major damage</p>
                  </div>
                </div>
                <div className="flex items-start space-x-3">
                  <Leaf className="h-6 w-6 text-green-600 mt-1 flex-shrink-0" />
                  <div>
                    <h4 className="font-semibold text-gray-900">Sustainable Farming</h4>
                    <p className="text-gray-600">
                      Promote eco-friendly agricultural practices and reduce chemical usage
                    </p>
                  </div>
                </div>
                <div className="flex items-start space-x-3">
                  <Users className="h-6 w-6 text-green-600 mt-1 flex-shrink-0" />
                  <div>
                    <h4 className="font-semibold text-gray-900">Inclusive Technology</h4>
                    <p className="text-gray-600">Make advanced agricultural technology accessible to all farmers</p>
                  </div>
                </div>
              </div>
            </div>

            <div className="relative">
              <img
                src="/placeholder.svg?height=600&width=500"
                alt="Farmer examining crops"
                className="rounded-lg shadow-xl"
              />
              <div className="absolute -bottom-6 -right-6 bg-white p-6 rounded-lg shadow-lg">
                <div className="text-center">
                  <div className="text-3xl font-bold text-green-600">95%</div>
                  <div className="text-sm text-gray-600">Accuracy Rate</div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>

      {/* Features Section */}
      <section id="features" className="py-20 bg-white">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="text-center mb-16">
            <h2 className="text-3xl sm:text-4xl font-bold text-gray-900 mb-4">Key Features</h2>
            <p className="text-xl text-gray-600 max-w-3xl mx-auto">
              Advanced AI technology designed specifically for the needs of farmers
            </p>
          </div>

          <div className="grid md:grid-cols-2 lg:grid-cols-3 gap-8">
            <Card className="border-green-100 hover:shadow-lg transition-shadow">
              <CardHeader>
                <Camera className="h-12 w-12 text-green-600 mb-4" />
                <CardTitle>Image-Based Detection</CardTitle>
                <CardDescription>
                  Simply take a photo of affected crops to get instant disease identification and treatment
                  recommendations
                </CardDescription>
              </CardHeader>
            </Card>

            <Card className="border-green-100 hover:shadow-lg transition-shadow">
              <CardHeader>
                <Wifi className="h-12 w-12 text-green-600 mb-4" />
                <CardTitle>Offline Support</CardTitle>
                <CardDescription>
                  Works without internet connectivity, perfect for remote rural areas with limited network access
                </CardDescription>
              </CardHeader>
            </Card>

            <Card className="border-green-100 hover:shadow-lg transition-shadow">
              <CardHeader>
                <Globe className="h-12 w-12 text-green-600 mb-4" />
                <CardTitle>Multilingual Interface</CardTitle>
                <CardDescription>
                  Available in multiple local languages to ensure accessibility for farmers across different regions
                </CardDescription>
              </CardHeader>
            </Card>

            <Card className="border-green-100 hover:shadow-lg transition-shadow">
              <CardHeader>
                <Zap className="h-12 w-12 text-green-600 mb-4" />
                <CardTitle>Real-Time Analysis</CardTitle>
                <CardDescription>
                  Get instant results with our optimized AI model that processes images in seconds
                </CardDescription>
              </CardHeader>
            </Card>

            <Card className="border-green-100 hover:shadow-lg transition-shadow">
              <CardHeader>
                <Shield className="h-12 w-12 text-green-600 mb-4" />
                <CardTitle>Treatment Recommendations</CardTitle>
                <CardDescription>
                  Receive specific, actionable treatment plans including organic and chemical solutions
                </CardDescription>
              </CardHeader>
            </Card>

            <Card className="border-green-100 hover:shadow-lg transition-shadow">
              <CardHeader>
                <Smartphone className="h-12 w-12 text-green-600 mb-4" />
                <CardTitle>Mobile-First Design</CardTitle>
                <CardDescription>
                  Optimized for smartphones with an intuitive interface that's easy to use in the field
                </CardDescription>
              </CardHeader>
            </Card>
          </div>
        </div>
      </section>

      {/* How It Works Section */}
      <section id="how-it-works" className="py-20 bg-gray-50">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="text-center mb-16">
            <h2 className="text-3xl sm:text-4xl font-bold text-gray-900 mb-4">How It Works</h2>
            <p className="text-xl text-gray-600 max-w-3xl mx-auto">Simple steps to identify and treat crop diseases</p>
          </div>

          <div className="grid md:grid-cols-3 gap-8">
            <div className="text-center">
              <div className="bg-green-100 rounded-full w-16 h-16 flex items-center justify-center mx-auto mb-6">
                <span className="text-2xl font-bold text-green-600">1</span>
              </div>
              <h3 className="text-xl font-bold text-gray-900 mb-4">Capture Image</h3>
              <p className="text-gray-600">
                Take a clear photo of the affected plant or crop using your smartphone camera
              </p>
            </div>

            <div className="text-center">
              <div className="bg-green-100 rounded-full w-16 h-16 flex items-center justify-center mx-auto mb-6">
                <span className="text-2xl font-bold text-green-600">2</span>
              </div>
              <h3 className="text-xl font-bold text-gray-900 mb-4">AI Analysis</h3>
              <p className="text-gray-600">
                Our advanced AI model analyzes the image and identifies potential diseases or issues
              </p>
            </div>

            <div className="text-center">
              <div className="bg-green-100 rounded-full w-16 h-16 flex items-center justify-center mx-auto mb-6">
                <span className="text-2xl font-bold text-green-600">3</span>
              </div>
              <h3 className="text-xl font-bold text-gray-900 mb-4">Get Solutions</h3>
              <p className="text-gray-600">
                Receive detailed diagnosis with treatment recommendations and prevention tips
              </p>
            </div>
          </div>
        </div>
      </section>

      {/* Impact Section */}
      <section id="impact" className="py-20 bg-white">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="text-center mb-16">
            <h2 className="text-3xl sm:text-4xl font-bold text-gray-900 mb-4">Expected Impact</h2>
            <p className="text-xl text-gray-600 max-w-3xl mx-auto">
              Transforming agriculture through accessible AI technology
            </p>
          </div>

          <div className="grid md:grid-cols-2 lg:grid-cols-4 gap-8 mb-16">
            <div className="text-center">
              <div className="bg-green-100 rounded-full w-20 h-20 flex items-center justify-center mx-auto mb-4">
                <Heart className="h-10 w-10 text-green-600" />
              </div>
              <div className="text-3xl font-bold text-gray-900 mb-2">50%</div>
              <div className="text-gray-600">Reduction in Crop Loss</div>
            </div>

            <div className="text-center">
              <div className="bg-green-100 rounded-full w-20 h-20 flex items-center justify-center mx-auto mb-4">
                <Users className="h-10 w-10 text-green-600" />
              </div>
              <div className="text-3xl font-bold text-gray-900 mb-2">10K+</div>
              <div className="text-gray-600">Farmers Reached</div>
            </div>

            <div className="text-center">
              <div className="bg-green-100 rounded-full w-20 h-20 flex items-center justify-center mx-auto mb-4">
                <Leaf className="h-10 w-10 text-green-600" />
              </div>
              <div className="text-3xl font-bold text-gray-900 mb-2">30%</div>
              <div className="text-gray-600">Less Chemical Usage</div>
            </div>

            <div className="text-center">
              <div className="bg-green-100 rounded-full w-20 h-20 flex items-center justify-center mx-auto mb-4">
                <Target className="h-10 w-10 text-green-600" />
              </div>
              <div className="text-3xl font-bold text-gray-900 mb-2">95%</div>
              <div className="text-gray-600">Accuracy Rate</div>
            </div>
          </div>

          <div className="bg-green-50 rounded-2xl p-8 text-center">
            <h3 className="text-2xl font-bold text-gray-900 mb-4">Join the Agricultural Revolution</h3>
            <p className="text-gray-600 mb-6 max-w-2xl mx-auto">
              Be part of the solution to create a more sustainable and productive agricultural future. Together, we can
              empower farmers with the tools they need to succeed.
            </p>
            <Button size="lg" className="bg-green-600 hover:bg-green-700 text-white px-8 py-3">
              Get Started Today
            </Button>
          </div>
        </div>
      </section>

      {/* Footer */}
      <footer className="bg-gray-900 text-white py-12">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="grid md:grid-cols-3 gap-8">
            <div>
              <div className="flex items-center space-x-2 mb-4">
                <Leaf className="h-8 w-8 text-green-400" />
                <span className="font-bold text-xl">CropAI</span>
              </div>
              <p className="text-gray-400 mb-4">
                Empowering farmers with AI-powered crop disease identification for sustainable agriculture.
              </p>
              <Badge className="bg-green-600 text-white">Samsung Solve for Tomorrow 2025</Badge>
            </div>

            <div>
              <h4 className="font-semibold text-lg mb-4">Project Goals</h4>
              <ul className="space-y-2 text-gray-400">
                <li className="flex items-center space-x-2">
                  <CheckCircle className="h-4 w-4 text-green-400" />
                  <span>Early disease detection</span>
                </li>
                <li className="flex items-center space-x-2">
                  <CheckCircle className="h-4 w-4 text-green-400" />
                  <span>Sustainable farming practices</span>
                </li>
                <li className="flex items-center space-x-2">
                  <CheckCircle className="h-4 w-4 text-green-400" />
                  <span>Inclusive technology access</span>
                </li>
                <li className="flex items-center space-x-2">
                  <CheckCircle className="h-4 w-4 text-green-400" />
                  <span>Rural community empowerment</span>
                </li>
              </ul>
            </div>

            <div>
              <h4 className="font-semibold text-lg mb-4">Contact</h4>
              <p className="text-gray-400 mb-2">
                For more information about this project or collaboration opportunities.
              </p>
              <Button
                variant="outline"
                className="border-green-400 text-green-400 hover:bg-green-400 hover:text-white bg-transparent"
              >
                Contact Team
              </Button>
            </div>
          </div>

          <div className="border-t border-gray-800 mt-8 pt-8 text-center text-gray-400">
            <p>&copy; 2025 AI-Powered Crop Disease Identifier. Developed for Samsung Solve for Tomorrow 2025.</p>
          </div>
        </div>
      </footer>
    </div>
  )
}
