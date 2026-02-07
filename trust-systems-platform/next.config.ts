import type { NextConfig } from "next";

const nextConfig: NextConfig = {
  serverExternalPackages: ["bcryptjs"],
  webpack: (config, { isServer }) => {
    if (!isServer) {
      // Prevent Monaco Editor worker chunks from breaking webpack
      config.resolve.fallback = {
        ...config.resolve.fallback,
        fs: false,
        path: false,
      };
    }
    return config;
  },
};

export default nextConfig;
